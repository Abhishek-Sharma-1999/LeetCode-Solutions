class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long long int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        long long int leftsum=0,rightsum=sum;
        
        for(int i=0;i<nums.size();i++)
        {
            leftsum+=nums[i];
            if(leftsum==rightsum)
            {
                return i;
            }
            rightsum-=nums[i];
        }
        
        return -1;
    }
};