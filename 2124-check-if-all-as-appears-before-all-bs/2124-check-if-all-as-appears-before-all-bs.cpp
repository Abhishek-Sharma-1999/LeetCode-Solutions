class Solution {
public:
    bool checkString(string s) {
        int B=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a' && B>=1)
                return false;
            else if(s[i]=='b')
                B++;
        }
        return true;
    }
};