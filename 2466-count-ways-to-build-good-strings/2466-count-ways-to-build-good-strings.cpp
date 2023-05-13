class Solution {
    const int M=1e9+7;
    int solve(int i,int low, int high, int zero, int one,vector<int>& ans)
    {
        if(i>high)
            return 0;
        
        if(ans[i]!=-1)
            return ans[i];
        
        bool addOne=false;
        
        if(i>=low && i<=high)
            addOne=true;
        
        int append_zero=solve(i+zero,low,high,zero,one,ans);
        
        int append_one=solve(i+one,low,high,zero,one,ans);
        
        return ans[i]=(append_zero+append_one+addOne)%M;   //agar range mein hua,toh addOne(+1)ho jaayega aur agar range mein nahin hua,toh (+0) add ho jaayega
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        
        vector<int>ans(high+1,-1);
        
        return solve(0,low,high,zero,one,ans);
    }
};