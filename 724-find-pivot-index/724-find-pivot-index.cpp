class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long long int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        long long int leftSum=0,rightSum=sum;
        for(int i=0;i<nums.size();i++)
        {
            rightSum-=nums[i];
            if(leftSum==rightSum)
            {
                return i;
            }
            leftSum+=nums[i];
        }
        
        return -1;
    }
};