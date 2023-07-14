class Solution {
public:
    // Using - Dp
        // int dp[100001];
        // int n,d;
        // int solve(int index,vector<int>& arr)
        // {
        //     int res=0;
        //     if(dp[index]!=-1)
        //         return dp[index];
        //     for(int j=index+1;j<n;j++)
        //     {
        //         int prev=arr[index];
        //         int curr=arr[j];
        //         if(curr-prev==d)
        //         {
        //             res=max(res,1+solve(j,arr));
        //         }
        //     }
        //     return dp[index]=res;
        // }
        // int longestSubsequence(vector<int>& arr, int difference) {
        //     n=arr.size();
        //     d=difference;
        //     memset(dp,-1,sizeof(dp));
        //     int res=0;
        //     for(int i=0;i<n;i++)
        //     {
        //         res=max(res,1+solve(i,arr));
        //     }
        //     return res;
    
    // Using MAP
    int longestSubsequence(vector<int>& arr, int difference) {
    int n=arr.size();
    int res=0;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        int curr=arr[i];    //Current Value
        int prev=curr-difference;   //Previous Value
        int length_till_prev=mp[prev];
        mp[curr]=length_till_prev+1;    //Current Element ka length, previos+1
        res=max(res,mp[curr]);
    }
    return res;
    }
};