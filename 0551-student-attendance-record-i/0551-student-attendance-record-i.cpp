class Solution {
public:
    bool checkRecord(string s) {
        int absent=0,late=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='A')
                absent++;
            if(s[i]=='L')
                late++;
            else
                late=0;
            if(absent>=2 || late>2)
                return false;
        }
        return 1;
    }
};