//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[1000][1000];
    Solution() {
        memset(dp,0,sizeof(dp));
    }
    string longestPalin (string s) {
        int n=s.size(),i,j,l, x=0, y=0, res=1;
        
        for(i=0;i<n;i++) {
            dp[i][i]=1;
            if(i>0) {
                if(s[i-1]==s[i]) {
                    dp[i-1][i]=1;
                    if(i-(i-1)+1>res) {
                        res=(i-(i-1)+1);
                        x=i-1, y=i;
                    }
                }
            }
        }
        for(l=2;l<n;l++) {
            j=l;
            for(i=0;i<=n-l;i++) {
                if(s[i]==s[j] && dp[i+1][j-1]) {
                    dp[i][j]=1;
                    if(j-i+1>res) {
                        res=(j-i+1);
                        x=i, y=j;
                    }
                }
                
                j++;
            }
        }
        return s.substr(x,y-x+1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends