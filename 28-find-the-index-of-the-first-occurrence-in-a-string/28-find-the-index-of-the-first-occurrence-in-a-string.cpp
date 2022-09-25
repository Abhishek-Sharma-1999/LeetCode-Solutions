class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="" || haystack.size()<needle.size())
        {
            return -1;
        }
        int n=haystack.size();
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(haystack[i]==needle[j])
            {
                j++;
                if(j==needle.size())
                {
                    return i-j+1;
                }
            }
            
            else
            {
                i=i-j;
                j=0;
            }
        }
        
        return -1;
    }
};