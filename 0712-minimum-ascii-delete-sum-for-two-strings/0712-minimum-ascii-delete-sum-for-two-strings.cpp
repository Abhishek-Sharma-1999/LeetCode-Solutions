class Solution {
public:
    int m,n;
    int dp[1001][1001];
    int solve(string &s1,string &s2,int i,int j)
    {
        if(i>=m && j>=n)    //agar dono out of bound chale gaye
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i>=m) //agar ek out of bound chla gya,lekin dusra abhi bhi hai,toh dusre vaale ke saare charters ko delete karenge
            return dp[i][j]=s2[j]+solve(s1,s2,i,j+1);
        if(j>=n) //agar ek out of bound chla gya,lekin dusra abhi bhi hai,toh dusre vaale ke saare charters ko delete karenge
            return dp[i][j]=s1[i]+solve(s1,s2,i+1,j);
        if(s1[i]==s2[j]) //agar dono equal hue,toh aage charaters ko match karenge,kyunki toh already euqal hai,aur hme strings ko equal hi karna hai
            return dp[i][j]=solve(s1,s2,i+1,j+1);
        int take_from_s1=s1[i]+solve(s1,s2,i+1,j);  //s1 mein se liya,toh us character ko add karenge aur phir aage ke liye call kar denge
        int take_from_s2=s2[j]+solve(s1,s2,i,j+1); //  //s2 mein se liya,toh us character ko add karenge aur phir aage ke liye call kar denge
        return dp[i][j]=min(take_from_s1,take_from_s2); //hme dono ka minimum return karna hai
    }
    int minimumDeleteSum(string s1, string s2) {
        m=s1.length();
        n=s2.length();
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,0,0);
    }
};