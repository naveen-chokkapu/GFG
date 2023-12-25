#User function Template for python3

class Solution:
    def numProvinces(self, adj, V):
        # code here 
        res = 0
        vis = set()
        def dfs(node):
            vis.add(node)
            for i in range(V):
                if adj[node][i] and i not in vis:
                    dfs(i)
                    
        for i in range(V):
            if i not in vis:
                res += 1
                dfs(i)
                
        return res;


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        V=int(input())
        adj=[]
        
        for i in range(V):
            temp = list(map(int,input().split()))
            adj.append(temp);
        
        ob = Solution()
        print(ob.numProvinces(adj,V))
# } Driver Code Ends