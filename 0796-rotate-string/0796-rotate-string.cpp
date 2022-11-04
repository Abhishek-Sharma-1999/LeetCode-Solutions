class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length())   //if their lengths are not equal
            return false;
        //s='abcde' -> s+s -> 'abcdeabcde' will have all the left shifts pattern as we have appended the same string after last character
        if((s+s).find(goal)==-1)    //Pattern not found
            return false;
        else
            return true;
    }
};