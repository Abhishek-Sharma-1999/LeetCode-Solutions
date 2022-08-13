class Solution {
public:
    int fib(int n) {
        // Recursive Way
        // if(n==0 || n==1)
        //     return n;
        // return fib(n-1)+fib(n-2);
        
        //DP
        if(n<2)
            return n;
        int ans[n+1];
        ans[0]=0;
        ans[1]=1;
        for(int i=2;i<=n;i++)
        {
            ans[i]=ans[i-1]+ans[i-2];
        }
        return ans[n];
    }
};