class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==0)
            return true;
        string str="";
        int i=0;
        while(i<s.size())
        {
            if( (s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9') )
            {
                str+=tolower(s[i]);
            }
            i++;
        }
        
        int low=0,high=str.size()-1;
        while(low<high)
        {
            if(str[low]!=str[high])
                return false;
            low++;
            high--;
        }
        return true;
    }
};