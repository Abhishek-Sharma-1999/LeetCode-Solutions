class Solution {
    bool isVowel(char ch)
    {
        if(ch=='a' || ch=='e' ||ch=='i' ||ch=='o' ||ch=='u' ||ch=='A' ||ch=='E' ||ch=='I' ||ch=='O' ||ch=='U')
            return true;
        return false;
    }
public:
    bool halvesAreAlike(string s) {
        int len=s.size();
        int c1=0;
        for(int i=0;i<(len/2);i++)
        {
            if(isVowel(s[i]))
                c1++;
        }
        for(int i=(len/2);i<len;i++)
        {
            if(isVowel(s[i]))
                c1--;
        }
        return c1==0;
    }
};