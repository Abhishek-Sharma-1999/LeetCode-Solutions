class Solution {
public:
    string reverseWords(string s) {
        // T.C.-> O(n)       S.C. -> O(n)
        // if(s.length()==0)
        //     return s;
        // stack<string> st;
        // for(int i=0;i<s.length();i++)
        // {
        //     if(s[i]==' ')   //agar space mila toh next iteration mein aa jao
        //         continue;
        //     string temp;
        //     while(i<s.length() && s[i]!=' ')    // agar space nahin mila toh use temporary string mein store karva lenge
        //     {
        //         temp=temp+s[i];
        //         i++;
        //     }
        //     st.push(temp);
        // }
        // string ans;
        // while(!st.empty())
        // {
        //     ans=ans+st.top();
        //     st.pop();
        //     if(!st.empty()) // agar stack empty nahin hai,matlab dusra word aaya hai, ek string pop out karne ke baad toh space(' ') ko add kar denge
        //     {
        //         ans+=' ';
        //     }
        // }
        // return ans;
        
        
        
        //T.C.- O(n)        S.C.- O(1)
        string ans;
        int i=0;
        while(i<s.length())
        {
            while(s[i]==' ')    // for spaces
                i++;
            
            string temp;
            
            while(i<s.length() && s[i]!=' ')    //agar hame space nahin mila toh temporary string mein us string ko add kar denge
            {
                temp+=s[i];
                i++;
            }
            if(temp.empty()==false)
                ans=temp+" "+ans;
        }
        ans.pop_back();
        return ans;
    }
};