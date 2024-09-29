import numpy as np
import matplotlib.pyplot as plt
import matplotlib.patches as patches

GRID_SIZE = 200

def process_rectangles(rectangles, K):
    grid = np.zeros((GRID_SIZE+1, GRID_SIZE+1), dtype=int)
    contributions = np.full((GRID_SIZE+1, GRID_SIZE+1), None)
    
    for i, (x1, y1, x2, y2) in enumerate(rectangles):
        grid[x1:x2, y1:y2] += 1
        for x in range(x1, x2):
            for y in range(y1, y2):
                if contributions[x, y] is None:
                    contributions[x, y] = set() 
                contributions[x, y].add(i)

    k_minus_1_overlap = []
    k_overlap = []
    k_minus_1_contributors = []
    
    for x1, y1, x2, y2 in rectangles:
        count_k_minus_1 = np.sum(grid[x1:x2, y1:y2] == K-1)
        count_k = np.sum(grid[x1:x2, y1:y2] == K)
        
        if count_k > 0:
            k_overlap.append((x1, y1, x2, y2))
        elif count_k_minus_1 > 0:
            k_minus_1_overlap.append((x1, y1, x2, y2))
            contributors = set()
            for x in range(x1, x2):
                for y in range(y1, y2):
                    if grid[x, y] == K-1:
                        contributors.update(contributions[x, y])
            k_minus_1_contributors.append(list(contributors))

    return k_minus_1_overlap, k_overlap, k_minus_1_contributors

def draw_rectangles(rectangles, k_minus_1_overlap, k_overlap, k_minus_1_contributors):
    fig, ax = plt.subplots()

    for rect in rectangles:
        ax.add_patch(
            patches.Rectangle(
                (rect[0], rect[1]),
                rect[2] - rect[0],
                rect[3] - rect[1],
                facecolor='none', edgecolor='black', linestyle='--', alpha=0.5
            )
        )
    
    for rect in k_overlap:
        ax.add_patch(
            patches.Rectangle(
                (rect[0], rect[1]),
                rect[2] - rect[0],
                rect[3] - rect[1],
                facecolor='red', edgecolor='none', alpha=0.7
            )
        )

    for i, rect in enumerate(k_minus_1_overlap):
        contributors = k_minus_1_contributors[i]
        for contributor in contributors:
            original_rect = rectangles[contributor]
            ax.add_patch(
                patches.Rectangle(
                    (original_rect[0], original_rect[1]),
                    original_rect[2] - original_rect[0],
                    original_rect[3] - original_rect[1],
                    facecolor='none', edgecolor='black', linestyle='-', linewidth=2
                )
            )
        ax.add_patch(
            patches.Rectangle(
                (rect[0], rect[1]),
                rect[2] - rect[0],
                rect[3] - rect[1],
                facecolor='blue', edgecolor='none', alpha=0.7
            )
        )
    
    plt.xlim(0, GRID_SIZE)
    plt.ylim(0, GRID_SIZE)
    plt.gca().set_aspect('equal', adjustable='box')
    plt.show()

rectangles = [
    (26, 3, 49, 21),
    (49, 21, 162, 27),
    (90, 59, 163, 126),
    (140, 26, 172, 136),
    (22, 58, 69, 167),
    (113, 57, 124, 95),
    (67, 1, 97, 102),
    (97, 153, 186, 165),
    (108, 115, 140, 149),
    (46, 51, 121, 155),
    (104, 18, 128, 88),
    (90, 99, 172, 125),
    (142, 64, 197, 107),
    (22, 28, 99, 143),
    (52, 99, 179, 150),
    (68, 71, 173, 131),
    (60, 163, 199, 181),
    (13, 68, 190, 95),
    (6, 101, 113, 172),
    (40, 42, 98, 113),
    (50, 55, 60, 142),
    (100, 46, 188, 197),
    (86, 125, 152, 196),
    (85, 29, 143, 135),
    (190, 25, 196, 167),
    (5, 158, 112, 186),
    (100, 146, 126, 194)
]

K = 3

k_minus_1_overlap, k_overlap, k_minus_1_contributors = process_rectangles(rectangles, K)

draw_rectangles(rectangles, k_minus_1_overlap, k_overlap, k_minus_1_contributors)
