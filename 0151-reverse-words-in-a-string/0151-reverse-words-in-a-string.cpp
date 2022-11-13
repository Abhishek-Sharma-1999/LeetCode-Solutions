class Solution {
public:
    string reverseWords(string s) {
        if(s.length()==0)
            return s;
        stack<string> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')   //agar space mila toh next iteration mein aa jao
                continue;
            string temp;
            while(i<s.length() && s[i]!=' ')    // agar space nahin mila toh use temporary string mein store karva lenge
            {
                temp=temp+s[i];
                i++;
            }
            st.push(temp);
        }
        string ans;
        while(!st.empty())
        {
            ans=ans+st.top();
            st.pop();
            if(!st.empty()) // agar stack empty nahin hai,matlab dusra word aaya hai, ek string pop out karne ke baad toh space(' ') ko add kar denge
            {
                ans+=' ';
            }
        }
        return ans;
    }
};