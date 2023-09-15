//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int solve(int index,int arr[],int N,int target) //Recursion
    {
        // base-case
        if(index>=N){
            return 0;
        }
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }
        int include=solve(index+1,arr,N,target-arr[index]);
        int exclude=solve(index+1,arr,N,target);
        return include || exclude;
    }
    int solve_memoization(int index,int arr[],int N,int target,vector<vector<int>>&dp)
    {
        // base-case
        if(index>=N){
            return 0;
        }
        if(target<0){
            return 0;
        }
        if(target==0){
            return 1;
        }
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        int include=solve_memoization(index+1,arr,N,target-arr[index],dp);
        int exclude=solve_memoization(index+1,arr,N,target,dp);
        return dp[index][target]=include || exclude;
    }
    int equalPartition(int N, int arr[])
    {
        int total=0;
        for(int i=0;i<N;i++)
        {
            total=total+arr[i];
        }
        if(total%2==1){ //agar odd hai,toh usko partition nahin kar paaenge
            return 0;
        }
        // return solve(0,arr,N,total/2);
        vector<vector<int>>dp(N,vector<int>(total+1,-1));
        return solve_memoization(0,arr,N,total/2,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends