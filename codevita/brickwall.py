from typing import List

def leastBricks(wall: List[List[int]]) -> int:
    gap_counts = {}
    total_rows = len(wall)
    max_gaps = 0

    for row in wall:
        cumulative_width = 0
        for i in range(len(row) - 1):
            brick_width = row[i]
            cumulative_width += brick_width
            gap_counts[cumulative_width] = gap_counts.get(cumulative_width, 0) + 1
            max_gaps = max(max_gaps, gap_counts[cumulative_width])

    return total_rows - max_gaps

n=int(input())
wall=[]
for i in range(n):
    r=input()
    y=len(r)
    a=0
    row=[]
    while(a<y):
        x=int(r[a])
        z=r[a+1]
        if z=='G':
            for i in range(x):
                row.append(1)
        else:
            for i in range(x):
                row.append(0)
        a+=2
    wall.append(row)
print(wall)


