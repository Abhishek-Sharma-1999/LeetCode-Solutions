class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st1(nums1.begin(),nums1.end());
        unordered_set<int>st2(nums2.begin(),nums2.end());
        vector<int>ans1,ans2;
        for(int i:st1)
        {
            if(st2.count(i)==0)
                ans1.push_back(i);
        }
        for(int i:st2)
        {
            if(st1.count(i)==0)
                ans2.push_back(i);
        }
        return {ans1,ans2};
    }
};