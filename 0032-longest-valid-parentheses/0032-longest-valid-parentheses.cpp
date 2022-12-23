class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1); //starting mein 0-1 kar denge push,kyunki agar starting mein hi close bracket aa gya toh stack mein pop-out karne ke liye kuch nahin hoga
        int len=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')   //open bracket hai toh push kar denge stack mein
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if(st.empty())
                {
                    st.push(i);
                }
                else
                {
                    len=max(len,i-st.top());
                }
            }
        }
        return len;
    }
};