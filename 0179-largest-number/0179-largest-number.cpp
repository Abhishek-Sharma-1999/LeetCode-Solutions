 
class Solution {
public:
   static bool compare(int a,int b)
    {
        string s1=to_string(a);
        string s2=to_string(b);
        return s1+s2>s2+s1;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),compare);
        string ans="";
        for(auto i:nums)
        {
            ans=ans+to_string(i);
        }
        if(ans[0]=='0')
        {
            return "0";
        }
        return ans;
    }
};