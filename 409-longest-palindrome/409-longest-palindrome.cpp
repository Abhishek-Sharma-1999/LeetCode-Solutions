class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
        
        int result=0;
        for(auto i:mp)
        {
            if(i.second % 2==0)
                result+=i.second;
            else
                result+=i.second-1;
        }
        if(result<s.length())
            return result+1;
        
        return result;
    }
};