class Solution {
public:
    bool help(string s, string t)
    {
        if(s.size()!=t.size())
            return false;
        unordered_map<char,char> mp;
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                if(mp[s[i]]!=t[i])
                    return false;
            }
            else
            {
                mp[s[i]]=t[i];
            }
        }
        return true;
    }
    
    bool isIsomorphic(string s, string t) {
        return help(s,t) && help(t,s);
    }
};