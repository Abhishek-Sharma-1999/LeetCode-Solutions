class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1)
        {
            return 0;
        }
        int product=1,left=0,right=0,ans=0;
        
        while(right<nums.size())
        {
            product*=nums[right];
            while(product>=k)
            {
                product/=nums[left];
                left++;
            }
            ans+=1+(right-left);
            right++;
        }
        
        return ans;
    }
};