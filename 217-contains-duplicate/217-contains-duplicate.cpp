class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       
        set<int>st;
        for(auto i:nums)
        {
            st.insert(i);
        }
        if(nums.size()!=st.size())
            return true;
        else
            return false;
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        // for(int i=0;i<n-1;i++)
        // {
        //     if(nums[i]==nums[i+1])
        //         return true;
        // }
        // return false;
    }
};