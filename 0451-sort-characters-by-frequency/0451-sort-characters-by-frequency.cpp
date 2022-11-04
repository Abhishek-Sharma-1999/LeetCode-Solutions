class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp; // Storing character and their frequency
        for(auto i:s)
        {
            mp[i]++;
        }
        priority_queue<pair<int,char>> pq;  //{frequency,character}
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }
        string ans="";
        while(!pq.empty())
        {
            int a=pq.top().first;
            char b=pq.top().second;
            string add(a,b);    // string add(3,x); -> add="xxx"
            ans+=add;
            pq.pop();
        }
        return ans;
    }
};