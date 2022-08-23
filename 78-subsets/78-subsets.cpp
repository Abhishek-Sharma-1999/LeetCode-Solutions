class Solution {
public:
    void helper(int index,vector<int>& nums,vector<int>& currSubset, vector<vector<int>>& ans)
    {
        if(index==nums.size())
        {
            ans.push_back(currSubset);
        }
        else
        {
            // to consider the element
            currSubset.push_back(nums[index]);
            helper(index+1,nums,currSubset,ans);
            
            currSubset.pop_back();
            // to not consider the element
            helper(index+1,nums,currSubset,ans);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> currSubset;
        vector<vector<int>> ans;
        helper(0,nums,currSubset,ans);
        return ans;
    }
};