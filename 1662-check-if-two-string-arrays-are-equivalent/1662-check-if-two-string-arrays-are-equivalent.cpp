class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a="",b="";
        for(auto i:word1)
        {
            a=a+i;
        }
        for(auto i:word2)
        {
            b=b+i;
        }
        return (a==b);
    }
};