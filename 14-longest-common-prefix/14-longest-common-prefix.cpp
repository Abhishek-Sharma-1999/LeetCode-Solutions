class Solution {
public:
    string Compare(string a,string b)
    {
        int n=min(a.size(),b.size());
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])
                break;
            else
                ans+=a[i];
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string s1=strs[0];
        for(int i=1;i<strs.size();i++)
        {
            s1=Compare(s1,strs[i]);
        }
        return s1;
    }
};