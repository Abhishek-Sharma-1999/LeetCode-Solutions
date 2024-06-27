class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>mp;
        int n=edges.size();
        for(auto &vec:edges)
        {
            int a=vec[0];
            int b=vec[1];
            mp[a]++;
            mp[b]++;
        }
        for(auto i:mp)
        {
            if(i.second==n)
                return i.first;
        }
        return -1;
    }
};