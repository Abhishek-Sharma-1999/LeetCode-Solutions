class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.length()<26)
        {
            return false;
        }
        vector<int> temp(26,0);
        for(int i=0;i<sentence.length();i++)
        {
            temp[sentence[i]-'a']++;
        }
        for(auto i:temp)
        {
            if(i==0)
            {
                return false;
            }
        }
        return true;
    }
};