class Solution {
public:
    int search(vector<int>& nums, int target) {
        //Approach-1
            // for(int i=0;i<nums.size();i++)
            // {
            //     if(nums[i]==target)
            //         return i;
            // }
            // return -1;
        // Approach-2
        int low=0,high=nums.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[low]<=nums[mid])    //left-part is sorted
            {
                if(target>=nums[low] && target<nums[mid])
                    high=mid-1;
                else
                    low=mid+1;
            }
            else    //Right-part is Sorted
            {
                if(target>nums[mid] && target<=nums[high])
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        return -1;
    }
};