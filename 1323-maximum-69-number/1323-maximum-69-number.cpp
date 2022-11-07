class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);    //Converting number to String (to_string)
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='6')
            {
                s[i]='9';
                break;
            }
        }
        return stoi(s); //stoi-> String to Integer
    }
};