class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        if(m!=n)    //agar dono ki length hi equal nahin hai,toh false hoga
        {
            return false;
        }
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        //matlab dono ki length equal hai,toh frequency aur same characters hone chaiye
        for(int i=0;i<m;i++)
        {
            freq1[word1[i]-'a']++;
            freq2[word2[i]-'a']++;
        }
        // checking if same characters exist
        for(int i=0;i<26;i++)
        {
            if( (freq1[i]==0 && freq2[i]>0) || (freq1[i]>0 && freq2[i]==0) )
                return false;
        }
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        for(int i=0;i<26;i++)
        {
            if(freq1[i]!=freq2[i])
                return false;
        }
        return true;
    }
};