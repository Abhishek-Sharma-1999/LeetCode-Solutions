//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    const int MOD=1000000007;
    //Function to count the number of ways in which frog can reach the top.
    long long solve_recursion(int n)
    {
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            ans=(solve_recursion(i-1)+solve_recursion(i-2)+solve_recursion(i-3))%MOD;
        }
        return ans;
    }
    
    long long solve_tabulation(int n)
    {
        vector<long long>dp(n+1,0);
        dp[0]=1;    // {}- {}
        dp[1]=1;    // 1-> {1}
        dp[2]=2;    // 2-> {1,1} and {2}
        for(int i=3;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2]+dp[i-3])%MOD;
        }
        return dp[n];
    }
    long long countWays(int n)
    {
        // return solve_recursion(n);
        vector<long long>dp(n+1,-1);
        return solve_tabulation(n);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends