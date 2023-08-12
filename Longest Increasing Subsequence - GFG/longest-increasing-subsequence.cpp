//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int solve_recursion(int n, int a[],int  index,int prev_index)
    {
        if(index==n)
        {
            return 0;
        }
        int take=0;
        if(prev_index==-1 || a[index]>a[prev_index])
        {
            take=1+solve_recursion(n,a,index+1,index);
        }
        int not_take=solve_recursion(n,a,index+1,prev_index);
        return max(take,not_take);
    }
    int solve_memoization(int n, int a[],int  index,int prev_index,vector<vector<int>>&dp)
    {
        if(index==n)
        {
            return 0;
        }
        if(dp[index][prev_index+1]!=-1)
        {
            return dp[index][prev_index+1];
        }
        int take=0;
        if(prev_index==-1 || a[index]>a[prev_index])
        {
            take=1+solve_memoization(n,a,index+1,index,dp);
        }
        int not_take=solve_memoization(n,a,index+1,prev_index,dp);
        return dp[index][prev_index+1]=max(take,not_take);
    }
    int solve_optimal(int n, int a[],vector<int>&ans)   //Most Optimal (Using Binary Search)
    {
        if(n==0)
        {
            return 0;
        }
        ans.push_back(a[0]);
        for(int i=1;i<n;i++)
        {
            if(a[i]>ans.back()) //agar jo current element aaya hai,vo hmare vector ke last elment se bda, toh use vector mein daalsakte hain, kyunki vo increasing sub-sequence hi bna rha hai
            {
                ans.push_back(a[i]);
            }
            else
            {   // lower_bound(ans.begin(),ans.end(),a[i]) -> ye address dega
                // lower_bound(ans.begin(),ans.end(),a[i])-ans.begin() -> ye index dega us element ka
                int index=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                ans[index]=a[i];
            }
        }
        return ans.size();
    }
    int longestSubsequence(int n, int a[])
    {
      // vector<vector<int>>dp(n,vector<int>(n+1,-1));
    //   return solve_memoization(n,a,0,-1,dp);
        vector<int>ans;
        if(n==0)
        {
            return 0;
        }
        ans.push_back(a[0]);
        for(int i=1;i<n;i++)
        {
            if(a[i]>ans.back()) //agar jo current element aaya hai,vo hmare vector ke last elment se bda, toh use vector mein daalsakte hain, kyunki vo increasing sub-sequence hi bna rha hai
            {
                ans.push_back(a[i]);
            }
            else
            {   // lower_bound(ans.begin(),ans.end(),a[i]) -> ye address dega
                // lower_bound(ans.begin(),ans.end(),a[i])-ans.begin() -> ye index dega us element ka
                int index=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                ans[index]=a[i];
            }
        }
        return ans.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends