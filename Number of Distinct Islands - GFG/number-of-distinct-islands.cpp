//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
    vector<pair<int,int>> t;
    int s=0,e=0;
    
    void dfs(vector<vector<int>> &grid, int i, int j, int n, int m) {
        grid[i][j]=0;
        t.push_back({i-s,j-e});
        for(int k=0;k<4;k++) {
            int x=dir[k][0]+i, y=dir[k][1]+j;
            if(x>=0 && y>=0 && x<n && y<m && grid[x][y])
            dfs(grid,x,y,n,m);
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size(), m=grid[0].size();
        set<vector<pair<int,int>>> res;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j]) {
                    s=i, e=j;
                    dfs(grid,i,j,n,m);
                    res.insert(t);
                    t.clear();
                }
            }
        }
        return res.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends