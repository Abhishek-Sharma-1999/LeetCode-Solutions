class Solution {
public:
    int KdanesAlgo(vector<int>& nums)
    {
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            maxi=max(maxi,sum);
            if(sum<0)
            {
                sum=0;
            }
        }
        return maxi;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        int linear_Sum=KdanesAlgo(nums);
        
        if(linear_Sum<0)    // If all elements are Negative
        {
            return linear_Sum;
        }
        
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            nums[i]=-nums[i];
        }
        
        int Circular_Sum=sum+KdanesAlgo(nums);
        
        return max(linear_Sum,Circular_Sum);
    }
};