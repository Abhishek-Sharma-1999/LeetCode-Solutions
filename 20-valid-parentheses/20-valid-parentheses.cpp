class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.length();
        char temp;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else 
            {
                if(st.size()==0)
                    return false;
                temp=st.top();
                if(s[i]==')' && temp!='(')
                    return false;
                else if(s[i]=='}' && temp!='{')
                    return false;
                else if(s[i]==']' && temp!='[')
                    return false;
                st.pop();
            }
        }
        
        if(st.empty())
            return true;
        else
            return false;
    }
};