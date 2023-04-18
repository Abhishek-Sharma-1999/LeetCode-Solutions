class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        for(int i=0;i<max(word1.length(),word2.length());i++)
        {
            if(i<word1.length())
                ans=ans+word1[i];
            if(i<word2.length())
                ans=ans+word2[i];
        }
        return ans;
    }
};