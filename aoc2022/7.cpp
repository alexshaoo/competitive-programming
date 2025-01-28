#include <bits/stdc++.h>
using namespace std;

#define cl(a, b) memset(a, b, sizeof(a))
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int mod = 1e9 + 7;

#include <bits/stdc++.h>
using namespace std;

// this straight up doesn't work lol
struct dir {
  string name;
  int size;
  vector<dir> subdirs;
};

int main() {
  dir root;
  root.name = "/";
  string line, command, arg1, arg2;
  while (getline(cin, line)) {
    stringstream ss(line);
    ss >> command;
    if (command == "cd") {
      ss >> arg1;
      if (arg1 == "/") {
        root.name = "/";
        root.size = 0;
        root.subdirs.clear();
      } else if (arg1 == "..") {
        if (root.name != "/") {
          int pos = root.name.find_last_of("/");
          root.name = root.name.substr(0, pos);
          root.size = 0;
          root.subdirs.clear();
        }
      } else {
        int pos = arg1.find_last_of("/");
        string name = arg1.substr(pos + 1);
        bool found = false;
        for (ull i = 0; i < root.subdirs.size(); i++) {
          if (root.subdirs[i].name == name) {
            root = root.subdirs[i];
            found = true;
            break;
          }
        }
        if (!found) {
          dir newdir;
          newdir.name = name;
          newdir.size = 0;
          root.subdirs.push_back(newdir);
          root = root.subdirs[root.subdirs.size() - 1];
        }
      }
    } else if (command == "ls") {
      ss >> arg1;
      if (arg1 == "..") {
        int pos = root.name.find_last_of("/");
        root.name = root.name.substr(0, pos);
        root.size = 0;
        root.subdirs.clear();
      } else {
        int pos = arg1.find_last_of("/");
        string name = arg1.substr(pos + 1);
        bool found = false;
        for (ull i = 0; i < root.subdirs.size(); i++) {
          if (root.subdirs[i].name == name) {
            root = root.subdirs[i];
            found = true;
            break;
          }
        }
        if (!found) {
          dir newdir;
          newdir.name = name;
          newdir.size = 0;
          root.subdirs.push_back(newdir);
          root = root.subdirs[root.subdirs.size() - 1];
        }
      }
    } else if (command == "dir") {
      ss >> arg1;
      dir newdir;
      newdir.name = arg1;
      newdir.size = 0;
      root.subdirs.push_back(newdir);
    } else if (command == "add") {
      ss >> arg1 >> arg2;
      int size = stoi(arg2);
      root.size += size;
    }
  }
  int sum = 0;
  for (ull i = 0; i < root.subdirs.size(); i++) {
    if (root.subdirs[i].size <= 100000) {
      sum += root.subdirs[i].size;
    }
  }
  cout << sum << endl;
}
