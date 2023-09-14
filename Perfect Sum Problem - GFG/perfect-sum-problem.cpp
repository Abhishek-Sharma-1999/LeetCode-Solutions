//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	const int MOD=1e9+7;
	
	int solve(int n,int sum,int arr[],vector<vector<int>> &dp)
	{
	    if(sum==0 && n==0){
	        return 1;
	    }
	    if(n==0){
	        return 0;
	    }
	    if(dp[n][sum]!=-1){
	        return dp[n][sum];
	    }
	    if(arr[n-1]<=sum){
	        return dp[n][sum]=(solve(n-1,sum-arr[n-1],arr,dp)+solve(n-1,sum,arr,dp))%MOD;
	    }
	    return dp[n][sum]=solve(n-1,sum,arr,dp);
	}
	int perfectSum(int arr[], int n, int sum)
	{
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(n,sum,arr,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends