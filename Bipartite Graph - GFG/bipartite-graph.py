class Solution:
	def isBipartite(self, V, adj):
		#code here
		vis = set()
		d = {}
		ok = 0
		
		def dfs(node, prev, cnt):
		    nonlocal ok
		    if ok: 
		        return
		    
		    d[node] = cnt
		    vis.add(node)
		    for i in adj[node]:
		        if i!=prev:
		            if i not in vis:
		                dfs(i, node, cnt+1)
		            else:
		                if (cnt-d[i])%2==0: ok=1
		    
		    
		    
		for i in range(V):
		    if ok: 
		        break
		    
		    if i not in vis:
		        dfs(i, -1, 0)
		        
	    return ok == 0


#{ 
 # Driver Code Starts

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		V, E = map(int, input().strip().split())
		adj = [[] for i in range(V)]
		for i in range(E):
			u, v = map(int, input().strip().split())
			adj[u].append(v)
			adj[v].append(u)
		obj = Solution()
		ans = obj.isBipartite(V, adj)
		if(ans):
			print("1")
		else:
			print("0")

# } Driver Code Ends