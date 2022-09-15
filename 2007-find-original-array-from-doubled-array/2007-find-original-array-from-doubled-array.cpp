class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
       vector<int> ans;
        int n=changed.size();
        if(n%2!=0)
        {
            return ans;
        }
        map<int,int> mp;
        sort(changed.begin(),changed.end());
        for(auto i:changed)
        {
            mp[i]++;
        }
        for(auto i:changed)
        {
            if(mp[i]==0)
            {
                continue;
            }
            if(mp[i*2]==0)
            {
                return {};
            }
                ans.push_back(i);
                mp[i]--;
                mp[i*2]--;         
        }
        return ans;
    }
};