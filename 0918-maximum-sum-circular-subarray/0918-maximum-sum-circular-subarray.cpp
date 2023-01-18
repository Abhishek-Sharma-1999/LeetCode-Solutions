class Solution {
    private:
    int kdaneMin(vector<int>& nums,int n)
    {
        int sum=nums[0];
        int minSum=nums[0];
        for(int i=1;i<n;i++){
            sum=min(sum+nums[i],nums[i]);
            minSum=min(minSum,sum);
        }
        return minSum;
    }
    
    
    int kdaneMax(vector<int>& nums,int n)
    {
        int sum=nums[0];
        int maxSum=nums[0];
        for(int i=1;i<n;i++){
            sum=max(sum+nums[i],nums[i]);
            maxSum=max(maxSum,sum);
        }
        return maxSum;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int SUM=accumulate(begin(nums),end(nums),0);
        int minSum=kdaneMin(nums,n);
        int maxSum=kdaneMax(nums,n);
        int CircularSum=SUM-minSum;
        if(maxSum>0)
        {
            return max(maxSum,CircularSum);
        }
        return maxSum;
    }
};