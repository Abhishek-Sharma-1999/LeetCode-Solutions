class Solution {
public:
    void helper(int index,vector<int>& nums,vector<int>& currSubset, set<vector<int>>& S)
    {
        if(index==nums.size())
        {
            S.insert(currSubset);
            return;
        }
        else
        {
            // to consider the element
            currSubset.push_back(nums[index]);
            helper(index+1,nums,currSubset,S);
            
            currSubset.pop_back();
            // to not consider the element
            helper(index+1,nums,currSubset,S);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> S;
        vector<int> currSubset;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        helper(0,nums,currSubset,S);
        ans.assign(S.begin(),S.end());
        return ans;  
    }
};