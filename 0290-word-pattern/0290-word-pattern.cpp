class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);// dog cat dog ->ye ek string hai,stringstream in sab ko alag-alg kar deta hai
        string i;
        vector<string>words;
        while(ss>>i) //Traversing stringstream and putting that in vector(of string)
        {
            words.push_back(i);
        }
        
        if(words.size()!=pattern.size())
        {
            return false;
        }
        unordered_map<char,string> mp;   //a->cat
        set<string>visited; //to keep track konsa word pehle aa chuka hai ya nahin
        for(int i=0;i<words.size();i++)
        {
            //first we have to check if that caracter already exists in our map
            if(mp.count(pattern[i]))
            {
                if(mp[pattern[i]] != words[i])
                    return false;
            }
            else
            {
                if(visited.find(words[i])!=visited.end())   //agar vo word alraedy set mein store hai,matlab vo ek baar visit ho chuka (vo ek baar kisi charcter ke saath a chuka hai,toh false bhejenge) 
                {
                    return false;
                }
                mp[pattern[i]]=words[i];
                visited.insert(words[i]);   //putting word into the stack
            }
                
        }
        return true;
    }
};