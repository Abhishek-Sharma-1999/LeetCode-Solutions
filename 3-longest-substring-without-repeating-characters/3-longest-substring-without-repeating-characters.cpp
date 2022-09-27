class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int ans=0;
        int start=0;
        int end=0;
        while(end<s.size())
        {
            auto it=st.find(s[end]);
            if(it==st.end())
            {
                if(end-start+1>ans)
                {
                    ans=end-start+1;
                }
                st.insert(s[end]);
                end++;
            }
            else
            {
                st.erase(s[start]);
                start++;
            }
        }
        
        return ans;
    }
};