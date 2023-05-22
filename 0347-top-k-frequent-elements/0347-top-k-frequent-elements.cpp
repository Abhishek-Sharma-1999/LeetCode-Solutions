class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;   //for storing element and it's frequency
        for(auto i:nums)
        {
            mp[i]++;
        }
        priority_queue<pair<int,int>>pq;   //for storing frequency, jiski frequency zayada hogi, vo heap mein top par aa jaayega (hep mein pair ki vo form mein store karenge)
        vector<int>res;
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }
        while(k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};