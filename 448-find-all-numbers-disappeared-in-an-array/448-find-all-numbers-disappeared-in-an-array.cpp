class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int element=abs(nums[i])-1;
            if(nums[element]>0)
                nums[element]=-nums[element];
        }
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                res.push_back(i+1);
        }
        return res;
    }
};