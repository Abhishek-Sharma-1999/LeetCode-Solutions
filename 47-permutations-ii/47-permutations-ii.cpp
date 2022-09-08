class Solution {
public:
    set<vector<int>> s;
    void helper(vector<int>& nums,int index)
   {
       if(index==nums.size())
       {
           s.insert(nums);
           return;
       }
       for(int i=index;i<nums.size();i++)
       {
           swap(nums[i],nums[index]);
           helper(nums,index+1);
           swap(nums[i],nums[index]);
       }
   }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        helper(nums,0);
        vector<vector<int>> res(s.begin(),s.end());
        return res;
    }
};