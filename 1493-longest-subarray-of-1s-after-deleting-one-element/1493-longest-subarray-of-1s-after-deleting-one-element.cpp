class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0,right=0,n=nums.size(),ans=0;
        int count_0=0;
        for(;right<n;right++)
        {
            if(nums[right]==0)
                count_0++;
            for(;count_0>1;left++)
            {
                if(nums[left]==0)
                    count_0--;
            }
            ans=max(ans,right-left+1);
        }
        return ans-1;   //kyunki ans mein ek element ko subtract karna hi hai
    }
};