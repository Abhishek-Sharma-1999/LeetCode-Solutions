//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int LCS(string &s1, string &s2,int n, int m,vector<vector<int>>&dp)
    {
        if(n<0 || m<0)
            return 0;
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        if(s1[n]==s2[m])
        {
            return dp[n][m]=1+LCS(s1,s2,n-1,m-1,dp);
        }
        else{
        int a=LCS(s1,s2,n-1,m,dp);
        int b=LCS(s1,s2,n,m-1,dp);
        return dp[n][m]=max(a,b);
        }
    }
    int lcs(int n, int m, string s1, string s2)
    {
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return LCS(s1,s2,n-1,m-1,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends