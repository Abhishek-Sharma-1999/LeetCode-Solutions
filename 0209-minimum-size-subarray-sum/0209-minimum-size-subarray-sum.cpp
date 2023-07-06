class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //sliding window
        int n=nums.size(),ans=INT_MAX,sum=0;
        int j=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            while(sum>=target)
            {
                sum-=nums[j];
                ans=min(i-j+1,ans);
                j++;
            }
        }
        return ans==INT_MAX ? 0 : ans;
    }
};