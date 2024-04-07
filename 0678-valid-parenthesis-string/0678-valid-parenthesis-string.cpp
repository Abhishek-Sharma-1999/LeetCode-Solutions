class Solution {
public:
    bool checkValidString(string s) {
        int open_bracket=0,close_bracket=0;
        int n=s.length();
        // Left to Right
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='*'){
                open_bracket++;
            }
            else{
                open_bracket--;
            }
            if(open_bracket<0){
                return false;
            }
        }
        // Right to Left
        for(int i=n-1;i>=0;i--){
            if(s[i]==')' || s[i]=='*'){
                close_bracket++;
            }
            else{
                close_bracket--;
            }
            if(close_bracket<0){
                return false;
            }
        }
        
        return true;
    }
};