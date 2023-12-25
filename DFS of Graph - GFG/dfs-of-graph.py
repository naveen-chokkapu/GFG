#User function Template for python3
from collections import deque
class Solution:
    
    #Function to return a list containing the DFS traversal of the graph.
    def dfsOfGraph(self, V, adj):
        # code here
        vis = set()
        res = []
        
        def dfs(node):
            res.append(node)            
            vis.add(node)
            for i in adj[node]:
                if i not in vis:
                    dfs(i)
            
        for i in range(V):
            if i not in vis:
                vis.add(i)
                dfs(i)
                
        return res;

#{ 
 # Driver Code Starts

if __name__ == '__main__':
    T=int(input())
    while T>0:
        V,E=map(int,input().split())
        adj=[[] for i in range(V+1)]
        for i in range(E):
            u,v=map(int,input().split())
            adj[u].append(v)
            adj[v].append(u)
        ob=Solution()
        ans=ob.dfsOfGraph(V,adj)
        for i in range(len(ans)):
            print(ans[i],end=" ")
        print()
        T-=1
# } Driver Code Ends