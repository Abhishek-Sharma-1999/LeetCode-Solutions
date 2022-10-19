class Solution {
public:
    // static bool cmp()(pair<int,string>&a,pair<int,string>&b)
    // {
    //     if(a.first<b.first) //jiski frequency km hai
    //         return true;
    //     else if(a.first==b.first && a.second>b.second)  //dono ki frequency same hai,lekin a chota hai b se
    //         return true;
    //     return false;
    // }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(string i:words)
        {
            mp[i]++;
        }
        
        priority_queue<pair<int,string>> pq;
        
        for(auto i:mp)
        {
            pq.push({-i.second,i.first});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        
        vector<string> res;
        while(k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};