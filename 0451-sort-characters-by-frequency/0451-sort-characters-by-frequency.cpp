class Solution {
public:
    string frequencySort(string s) {
        string ans="";
        unordered_map<char,int> mp;
        for(auto i:s)
        {
            mp[i]++;
        }
        priority_queue<pair<int,char>> pq;
        
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }
        while(!pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            for(int i=0;i<x.first;i++)
            {
                ans+=x.second;
            }
        }
        return ans;
    }
};