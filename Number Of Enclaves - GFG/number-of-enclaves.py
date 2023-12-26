#User function Template for python3

from typing import List
from collections import deque

class Solution:    
    def numberOfEnclaves(self, grid: List[List[int]]) -> int:
        # code here
        dir = [[0,1],[1,0],[-1,0],[0,-1]]
        n,m = len(grid), len(grid[0])
        
        def check(i,j):
            return (i>=0 and j>=0 and i<n and j<m and grid[i][j])
        
        def bfs(i,j):
            q = deque()
            q.append([i,j])
            grid[i][j]=0
            while q:
                t = q.popleft()
                for k in range(4):
                    x = dir[k][0]+t[0]; y = dir[k][1]+t[1]
                    if check(x,y):
                        grid[x][y]=0
                        q.append([x,y])
        
        for i in range(n):
            for j in range(m):
                if (i==0 or j==0 or i==n-1 or j==m-1) and grid[i][j]:
                    bfs(i,j)
                    
        res = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j]: res += 1
                
        return res

#{ 
 # Driver Code Starts
#Initial Template for Python 3


if __name__ == "__main__":
    for _ in range(int(input())):
        n, m = map(int,input().strip().split())
        grid = []
        for i in range(n):
            grid.append([int(i) for i in input().strip().split()])

        obj=Solution()
        print(obj.numberOfEnclaves(grid))
# } Driver Code Ends