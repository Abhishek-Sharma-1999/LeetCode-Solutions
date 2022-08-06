class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long int res=INT_MIN;
        long long prod=1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            prod=prod*nums[i];
            if(prod>res)
                res=prod;
            if(prod==0)
                prod=1;
        }
        
        prod=1;
        
        for(int i=n-1;i>=0;i--)
        {
            prod=prod*nums[i];
            if(prod>res)
                res=prod;
            if(prod==0)
                prod=1;
        }
        
        return res;
    }
};