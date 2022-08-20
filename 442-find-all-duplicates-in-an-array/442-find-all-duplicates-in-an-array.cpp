class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int value=abs(nums[i])-1;
            if(nums[value]>0)
            {
                nums[value]=nums[value]*(-1);
            }
            else
            {
                v.push_back(value+1);
            }
        }
        return v;
    }
};