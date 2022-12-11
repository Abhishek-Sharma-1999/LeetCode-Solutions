class Solution {
public:
    int scoreOfParentheses(string s) {
       // Stack Solution   T.C.-> O(n)      S.C.-> O(n)
        // stack<int>st;
        // int score=0;
        // for(int i=0;i<s.length();i++)
        // {
        //     if(s[i]=='(')
        //     {
        //         st.push(score);
        //         score=0;
        //     }
        //     else
        //     {
        //         score=st.top()+max(1,2*score);
        //         st.pop();
        //     }
        // }
        // return score;
        
        // Optimised Solution  T.C.-> O(n)      S.C.-> O(1)
        int depth=0,res=0;
        char prev='(';
        for(auto i:s)
        {
            if(i=='(')
            {
                depth++;
            }
            else
            {
                depth--;
                if(prev=='(')
                    res=res+pow(2,depth);
            }
            prev=i;
        }
        return res;
    }
};