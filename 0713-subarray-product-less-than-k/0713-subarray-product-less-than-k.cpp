class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long int left=0,right=0,n=nums.size(),ans=0;
        long long int prod=1;

        for(;right<n;right++)
        {
            prod*=nums[right];
        
            for(;prod>=k && left<=right;left++)
            {
                prod/=nums[left];
            }
            ans+=(right-left+1);
        }
        return ans;
    }
};