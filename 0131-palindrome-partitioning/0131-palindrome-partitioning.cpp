class Solution {
public:
    bool isPalaindrome(string &s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    void help(int index,string s,vector<string>& path,vector<vector<string>>& ans)
    {
        if(index==s.length())
        {
            ans.push_back(path);
            return;
        }
        for(int i=index;i<s.length();i++)
        {
            if(isPalaindrome(s,index,i))
            {
                path.push_back(s.substr(index,i-index+1));
                help(i+1,s,path,ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        help(0,s,path,ans);
        return ans;    
    }
};