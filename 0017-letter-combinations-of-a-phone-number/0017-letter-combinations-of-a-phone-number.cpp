class Solution {
public:
    void solve(int index,string digits,vector<string> &ans,string &temp,unordered_map<char,string> &mp)
    {
        if(index>=digits.length())
        {
            ans.push_back(temp);
            return;
        }
        char ch=digits[index];
        string str=mp[ch];
        for(int i=0;i<str.length();i++)
        {
            temp.push_back(str[i]);
            solve(index+1,digits,ans,temp,mp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)
            return {};
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        vector<string>ans;
        string temp="";
        solve(0,digits,ans,temp,mp);
        return ans;
    }
};