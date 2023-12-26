from collections import deque

class Solution:

    #Function to find distance of nearest 1 in the grid for each cell.
	def nearest(self, grid):
		#Code here
		dir = [[0,1],[1,0],[0,-1],[-1,0]]
		q = deque()
		n,m = len(grid), len(grid[0])
		vis = set()
		
		for i in range(n):
		    for j in range(m):
		        if grid[i][j]: 
		            grid[i][j] = -1
		            q.append([i,j])
		        
        def check(i,j):
            return (i>=0 and j>=0 and i<n and j<m and grid[i][j]==0)
		        
        q.append([-1,-1])
        res = 1
        while q:
            t = q.popleft()
            if q and t == [-1,-1]:
                q.append([-1,-1])
                res += 1; continue
                
            for i in range(4):
                x = t[0]+dir[i][0]
                y = t[1]+dir[i][1]
                if check(x,y):
                    grid[x][y] = res
                    q.append([x,y])
                    
            # print(q)
		        
		for i in range(n):
		    for j in range(m):
		        if grid[i][j]==-1: grid[i][j]=0
		        
        return grid
		


#{ 
 # Driver Code Starts

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		n, m = map(int, input().split())
		grid = []
		for _ in range(n):
			a = list(map(int, input().split()))
			grid.append(a)
		obj = Solution()
		ans = obj.nearest(grid)
		for i in ans:
			for j in i:
				print(j, end = " ")
			print()

# } Driver Code Ends