class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0,zeroes=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                zeroes++;
            else
                zeroes=0;
            ans+=zeroes;
            
        }
        return ans;
    }
};