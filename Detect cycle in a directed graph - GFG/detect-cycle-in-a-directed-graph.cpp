//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    // Function to detect cycle in a directed graph.
    public:
        bool isCyclic(int V, vector<int> adj[]) {
            // Kahn's Algo
            int inD[V] = {0};
            for(int i=0;i<V;i++) {
                for(auto j:adj[i]) inD[j]++;
            }
            queue<int> Q;
            for(int i=0;i<V;i++) {
                if(!inD[i]) Q.push(i);
            }
            int cnt=0;
            while(!Q.empty()) {
                int node = Q.front();
                Q.pop(); cnt++;
                for(auto it:adj[node]) {
                    inD[it]--;
                    if(!inD[it]) Q.push(it);
                }
            }
            if(cnt!=V) return 1;
            return 0;
        }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends