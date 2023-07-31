//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string S){
        vector<vector<int>> dp(S.size(), vector<int> (S.size(),0));
        int i,j,x=0,y=0;
        bool b=0;
        for(i=0;i<S.size();i++) {
            dp[i][i]=1;
            if(i>0) {
                if(S[i-1]==S[i]) {
                    dp[i-1][i]=1; 
                    if(!b) {
                        x=i-1,y=i; b=1;
                    }
                }
            }
        }
        for(i=2;i<S.size();i++) {
            b=0;
            for(j=0;j<S.size()-i;j++) {
                if(S[j]==S[i+j] && dp[j+1][i+j-1]) {
                    dp[j][i+j]=1;
                    if(!b) {
                        x=j,y=i+j; b=1;
                    }
                }
            }
        }
        string res;
        for(i=x;i<=y;i++) res+=S[i];
        return res;
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends