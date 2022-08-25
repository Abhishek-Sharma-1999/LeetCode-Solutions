class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for(auto i:magazine)
        {
            mp[i]++;
        }
        
        for(auto i:ransomNote)
        {
            if(!mp[i])
                return false;
            mp[i]--;
        }
        return true;
    }
};