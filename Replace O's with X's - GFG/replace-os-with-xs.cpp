//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution{
public:
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    
    void dfs(vector<vector<char>> &mat, int i, int j, int n, int m) {
        mat[i][j]='Y';
        for(int k=0;k<4;k++) {
            int x=dir[k][0]+i, y=dir[k][1]+j;
            if(x>=0 && y>=0 && x<n && y<m && mat[x][y]=='O')
            dfs(mat,x,y,n,m);
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if((i==0 || j==0 || i==n-1 || j==m-1) && mat[i][j]=='O')
                dfs(mat,i,j,n,m);
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j]=='O') mat[i][j]='X';
                if(mat[i][j]=='Y') mat[i][j]='O';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends