from typing import List
class Solution:
    #Function to detect cycle in an undirected graph.
	def isCycle(self, V: int, adj: List[List[int]]) -> bool:
		#Code here
		vis = set()
		ok = 0
		def dfs(node, prev):
		    nonlocal ok
		    if ok: return
		    vis.add(node)
		    for i in adj[node]:
		        if i!=prev:
		            if i not in vis:
		                dfs(i,node)
		            else:
		                ok=1; return
		            
        for i in range(V):
            if ok: return 1
		    if i not in vis:
		        dfs(i,-1)
		        
        return 0

#{ 
 # Driver Code Starts

if __name__ == '__main__':

	T=int(input())
	for i in range(T):
		V, E = map(int, input().split())
		adj = [[] for i in range(V)]
		for _ in range(E):
			u, v = map(int, input().split())
			adj[u].append(v)
			adj[v].append(u)
		obj = Solution()
		ans = obj.isCycle(V, adj)
		if(ans):
			print("1")
		else:
			print("0")

# } Driver Code Ends