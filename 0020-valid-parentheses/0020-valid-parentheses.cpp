class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.size()==0)    //stack empty hai, toh false
                    return false;
                else if(st.top()=='(' && s[i]!=')')
                    return false;
                else if(st.top()=='[' && s[i]!=']')
                    return false;
                else if(st.top()=='{' && s[i]!='}')
                    return false;
                st.pop();
            }
        }
        if(st.size()!=0)    //abhi bhi stack ,mein element hai
            return false;
         return true;
    }
};