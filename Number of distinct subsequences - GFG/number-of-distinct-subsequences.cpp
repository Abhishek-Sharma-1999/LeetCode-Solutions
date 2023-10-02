//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    int MOD=1e9+7;
	    int n=s.size();
	    unordered_map<char,int> mp;
	    vector<int>dp(n+1);
	    dp[0]=1;
	    for(int i=1;i<=n;i++)
	    {
	        dp[i]=(2*dp[i-1])%MOD;
	        char ch=s[i-1];
	        if(mp[ch])
	        {
	            int j=mp[ch];
	            dp[i]=(dp[i]-dp[j-1]+MOD)%MOD;
	        }
	        mp[ch]=i;
	    }
	    return dp[n];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends