class Solution {
public:
    bool validPalindrome(string s) {
        int start=0,end=s.size()-1;
        int count1=0,count2=0;
        // For Starting
        while(start<end)
        {
            if(s[start]==s[end])
            {
                start++;
                end--;
            }
            else
            {
                count1++;   // if starting character does not match,we increment start and compare with rest of the characters
                start++;
            }
        }
        
        start=0;
        end=s.size()-1;
        
        while(start<end)
        {
            if(s[start]==s[end])
            {
                start++;
                end--;  // if ending character does not match,we decement end and compare with rest of the character
            }
            else
            {
                count2++;
                end--;
            }
        }
        
        if(count1==0 || count2==0)  // Valid Palaindrome
        {
            return true;
        }
        
        if(count1==1 || count2==1)  // After removing 1 character either from start or end, string is Palaindrome
        {
            return true;
        }
        
        return false;
    }
};