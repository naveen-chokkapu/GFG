#User function Template for python3

import sys
sys.setrecursionlimit(10**8)
class Solution:
    def numIslands(self,grid):
        #code here
        dir = [[0,1],[1,0],[0,-1],[-1,0],[1,1],[-1,-1],[1,-1],[-1,1]]
        n,m = len(grid), len(grid[0])
        
        def check(i,j):
            return (i>=0 and j>=0 and i<n and j<m and grid[i][j])
        
        def dfs(i,j):
            for k in range(8):
                x = i+dir[k][0]
                y = j+dir[k][1]
                if check(x,y):
                    grid[x][y]=0
                    dfs(x,y)
        
        res = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j]:
                    res += 1
                    dfs(i,j)
                    
        return res;


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__=="__main__":
    for _ in range(int(input())):
        n,m=map(int,input().strip().split())
        grid=[]
        for i in range(n):
            grid.append([int(i) for i in input().strip().split()])
        obj=Solution()
        print(obj.numIslands(grid))
# } Driver Code Ends