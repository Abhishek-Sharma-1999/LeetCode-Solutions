class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a==b)        // Both Strings are Same
            return -1;
        
        return max(a.length(),b.length());
    }
};