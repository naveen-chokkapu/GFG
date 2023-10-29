//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int f(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
        if(i==s.size() || j==t.size())
        return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) {
            return dp[i][j]=1+f(s,t,i+1,j+1,dp);
        }
        return dp[i][j]=max(f(s,t,i+1,j,dp), f(s,t,i,j+1,dp));
    }
    int longestPalinSubseq(string A) {
        //code here
        string t=A;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(A.size(), vector<int> (t.size(),-1));
        return f(A, t, 0, 0, dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends