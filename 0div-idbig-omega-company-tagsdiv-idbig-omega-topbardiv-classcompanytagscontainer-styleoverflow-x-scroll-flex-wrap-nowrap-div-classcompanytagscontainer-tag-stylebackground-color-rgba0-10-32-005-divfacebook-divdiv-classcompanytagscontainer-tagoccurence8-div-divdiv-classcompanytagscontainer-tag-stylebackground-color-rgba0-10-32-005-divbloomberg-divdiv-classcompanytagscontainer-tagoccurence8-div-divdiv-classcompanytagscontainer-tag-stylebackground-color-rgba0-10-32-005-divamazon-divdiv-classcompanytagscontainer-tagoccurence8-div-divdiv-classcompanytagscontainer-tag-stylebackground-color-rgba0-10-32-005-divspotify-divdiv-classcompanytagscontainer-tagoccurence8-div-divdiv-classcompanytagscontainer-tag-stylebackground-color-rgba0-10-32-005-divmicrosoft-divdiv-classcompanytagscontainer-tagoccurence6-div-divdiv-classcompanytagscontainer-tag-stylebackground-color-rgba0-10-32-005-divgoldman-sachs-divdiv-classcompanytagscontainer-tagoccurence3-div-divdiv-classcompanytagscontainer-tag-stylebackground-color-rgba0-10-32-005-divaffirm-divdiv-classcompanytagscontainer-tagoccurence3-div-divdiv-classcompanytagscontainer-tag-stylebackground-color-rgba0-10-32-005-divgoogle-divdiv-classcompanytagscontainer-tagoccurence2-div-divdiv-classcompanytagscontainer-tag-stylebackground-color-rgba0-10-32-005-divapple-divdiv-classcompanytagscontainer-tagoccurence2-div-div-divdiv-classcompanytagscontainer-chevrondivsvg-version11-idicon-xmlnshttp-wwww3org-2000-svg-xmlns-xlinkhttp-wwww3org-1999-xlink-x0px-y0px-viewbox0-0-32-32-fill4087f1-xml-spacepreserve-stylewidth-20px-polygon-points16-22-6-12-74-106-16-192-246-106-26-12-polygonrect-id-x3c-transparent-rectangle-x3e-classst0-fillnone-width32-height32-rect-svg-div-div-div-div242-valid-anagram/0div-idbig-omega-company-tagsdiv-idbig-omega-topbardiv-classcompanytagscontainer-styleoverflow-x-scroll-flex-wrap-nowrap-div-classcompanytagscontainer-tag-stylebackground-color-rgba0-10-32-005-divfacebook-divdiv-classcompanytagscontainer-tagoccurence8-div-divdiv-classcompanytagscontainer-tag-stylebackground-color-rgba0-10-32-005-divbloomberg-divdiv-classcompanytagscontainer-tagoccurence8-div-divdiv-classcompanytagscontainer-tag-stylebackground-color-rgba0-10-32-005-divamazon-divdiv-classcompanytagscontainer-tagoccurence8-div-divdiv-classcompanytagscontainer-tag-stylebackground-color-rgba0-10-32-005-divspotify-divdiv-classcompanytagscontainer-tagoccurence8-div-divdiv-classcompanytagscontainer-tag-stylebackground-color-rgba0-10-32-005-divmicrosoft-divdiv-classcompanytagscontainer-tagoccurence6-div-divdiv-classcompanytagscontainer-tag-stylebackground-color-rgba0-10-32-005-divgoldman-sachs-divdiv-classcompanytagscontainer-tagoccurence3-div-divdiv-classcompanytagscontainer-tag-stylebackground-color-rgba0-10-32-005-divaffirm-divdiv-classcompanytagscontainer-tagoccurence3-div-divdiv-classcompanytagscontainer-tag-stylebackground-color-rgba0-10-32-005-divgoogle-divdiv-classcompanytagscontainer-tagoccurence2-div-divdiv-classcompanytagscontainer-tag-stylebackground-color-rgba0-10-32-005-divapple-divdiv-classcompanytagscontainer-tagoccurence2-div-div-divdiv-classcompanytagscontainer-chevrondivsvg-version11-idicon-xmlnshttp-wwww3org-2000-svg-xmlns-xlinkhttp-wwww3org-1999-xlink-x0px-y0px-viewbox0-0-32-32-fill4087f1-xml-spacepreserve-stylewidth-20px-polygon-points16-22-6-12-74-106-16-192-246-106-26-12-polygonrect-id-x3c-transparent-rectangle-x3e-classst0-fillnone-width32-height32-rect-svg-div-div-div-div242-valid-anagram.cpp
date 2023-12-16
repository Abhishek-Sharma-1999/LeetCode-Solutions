class Solution {
public:
    bool isAnagram(string s, string t) {
        // Approach-1
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // return s==t;
        
        // Approach-2
        if(s.size()!=t.size()){
            return false;
        }
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto i:mp)
        {
            if(i.second!=0)
                return false;
        }
        return true;
    }
};