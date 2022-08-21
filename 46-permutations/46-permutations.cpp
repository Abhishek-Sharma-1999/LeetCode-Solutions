class Solution {
public:
    void helper(vector<int>& nums,int index,vector<vector<int>>& res)
    {
        if(index==nums.size())
        {
            res.push_back(nums);
            return;
        }
        
        for(int k=index;k<nums.size();k++)
        {
            swap(nums[index],nums[k]);
            helper(nums,index+1,res);
            swap(nums[index],nums[k]);
        }
        // return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums,0,res);
        return res;
    }
};