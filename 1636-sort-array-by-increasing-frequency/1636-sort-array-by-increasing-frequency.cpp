class Solution {
    static bool cmp(pair<int,int> &a,pair<int,int> &b)
    {
        if(a.second==b.second)
            return a.first>b.first;
        return a.second<b.second;
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        if(nums.size()==1)
            return nums;
        map<int,int> mp;
        vector<int>ans;
        for(auto i:nums)
        {
            mp[i]++;
        }
        vector<pair<int,int>> freq;
        for(auto i:mp)
        {
            freq.push_back(i);
        }
        sort(freq.begin(),freq.end(),cmp);
        int k=0;
        for(auto i:freq)
        {
            while(i.second!=0)
            {
                nums[k]=i.first;
                k++;
                i.second--;
            }
        }
        return nums;
    }
};