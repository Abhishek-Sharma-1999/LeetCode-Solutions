class Solution {
public:
    void solve(int open,int close,string &curr,vector<string>& ans)
    {
        if(open==0 && close==0)
        {
            ans.push_back(curr);
            return;
        }
        if(open>0)
        {
            string s=curr;
            s.push_back('(');
            solve(open-1,close,s,ans);
        }
        if(close>open)
        {
            string c=curr;
            c.push_back(')');
            solve(open,close-1,c,ans);
        }
    }
        
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr="";
        solve(n,n,curr,ans);
        return ans;
    }
};