class Solution {
public:
    string reverseWords(string s) {
        if(s.length()==0)
            return s;
        stack<string> st;
        for(int i=0;i<s.length();i++)
        {
            string temp;
            if(s[i]==' ')
                continue;
            while(i<s.length() && s[i]!=' ')
            {
                temp+=s[i];
                i++;
            }
            st.push(temp);
        }
        
        string ans;
        while(st.size()!=0)
        {
            ans+=st.top();
            st.pop();
            if(st.size()!=0)
            {
                ans+=' ';
            }
        }
        
        return ans;
    }
};