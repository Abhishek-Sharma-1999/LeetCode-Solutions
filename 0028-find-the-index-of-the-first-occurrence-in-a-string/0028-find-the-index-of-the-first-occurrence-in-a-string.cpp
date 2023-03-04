class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.length();
        int n=needle.length();
        if(n>m)
            return -1;
        int i=0,j=0,start=0;
        while(i<m && j<n)
        {
            if(haystack[i]==needle[j])
            {
                if(i-start+1==n)
                    return start;
                i++;
                j++;
            }
            else
            {
                j=0;
                start++;
                i=start;
            }
        }
        return -1;
    }
};