class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // Approach-1
        // Using Xor Property
        // int ans=0;
        // for(int i=0;i<nums.size();i++)
        // {
            // ans=ans^nums[i];
        // }
        // return ans;
        
        // Approach-2
        //using binary search
        int low=0,high=nums.size()-1,mid;
             
        while(low<high)
        {
             mid=low+(high-low)/2;
            if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid]==nums[mid-1]))
                low=mid+1;
            else
                high=mid;
        }
        return nums[low];
    }
};