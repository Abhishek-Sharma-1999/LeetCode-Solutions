class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,right=0,n=s.length(),ans=0;
        unordered_map<char,int> mp;
        for(;right<n;right++)
        {
            // new character enters and might make the window invalid
            mp[s[right]]++;
            for(;mp[s[right]]>1;left++)
            {
                mp[s[left]]--;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};