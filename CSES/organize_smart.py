import os
import shutil
import urllib.request
import re

# ---------------------------------------------------------
# CONFIGURATION
# ---------------------------------------------------------
URL = "https://cses.fi/problemset/list/"
# Set to False to actually move files. True will just print what would happen.
DRY_RUN = False 
# ---------------------------------------------------------

def slugify(name):
    """Converts 'Introductory Problems' to 'introductory-problems'"""
    return name.lower().strip().replace(' ', '-').replace('/', '-')

def fetch_mapping():
    print(f"Fetching problem list from {URL}...")
    try:
        with urllib.request.urlopen(URL) as response:
            html = response.read().decode('utf-8')
    except Exception as e:
        print(f"Error fetching URL: {e}")
        exit(1)

    # Split the HTML by <h2> tags to separate categories
    # This assumes the structure: <h2>Category Name</h2> ... <ul class="task-list"> ... </ul>
    sections = re.split(r'<h2[^>]*>', html)
    
    mapping = {} # { '1068': 'introductory-problems', ... }
    
    # Skip the first chunk (before the first h2)
    for section in sections[1:]:
        # Extract Category Name (everything before the closing </h2>)
        cat_match = re.search(r'(.*?)</h2>', section, re.DOTALL)
        if not cat_match:
            continue
            
        category_name = cat_match.group(1).strip()
        folder_name = slugify(category_name)
        
        # Find all Task IDs in this section
        # Looking for href="/problemset/task/1068"
        tasks = re.findall(r'/problemset/task/(\d+)', section)
        
        for task_id in tasks:
            mapping[task_id] = folder_name
            
    return mapping

def main():
    mapping = fetch_mapping()
    print(f"Found {len(mapping)} problems across distinct categories.")
    
    # Get all .cpp files in current directory
    files = [f for f in os.listdir('.') if f.endswith('.cpp') and f != os.path.basename(__file__)]
    
    for filename in files:
        task_id = filename.replace('.cpp', '')
        
        if task_id in mapping:
            target_folder = mapping[task_id]
            
            # Handle special cases or manual folders you already made
            if not os.path.exists(target_folder):
                if DRY_RUN:
                    print(f"[Dry Run] Would create folder: {target_folder}/")
                else:
                    os.makedirs(target_folder)
                    print(f"Created folder: {target_folder}/")
            
            # Move the file
            src = filename
            dst = os.path.join(target_folder, filename)
            
            if DRY_RUN:
                print(f"[Dry Run] Would move {src} -> {dst}")
            else:
                try:
                    shutil.move(src, dst)
                    print(f"Moved {src} -> {target_folder}/")
                except Exception as e:
                    print(f"Error moving {src}: {e}")
        else:
            print(f"Skipped {filename} (ID {task_id} not found in online list)")

if __name__ == "__main__":
    main()
