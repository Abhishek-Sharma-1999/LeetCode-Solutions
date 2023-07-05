class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Sliding Window
        int left=0,ans=0,right=0,count_zero=0;
        for(right=0;right<nums.size();right++)
        {
            if(nums[right]==0)
                count_zero++;
            while(count_zero>1)
            {
                if(nums[left]==0)
                    count_zero--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans-1;
    }
};