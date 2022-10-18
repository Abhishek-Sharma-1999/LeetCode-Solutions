class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        if(n==1)
        {
            ans;
        }
        
        for(int k=2;k<=n;k++)
        {
            string last_string=ans;
            int i=0;
            int l=ans.size();   //last_index
            ans="";
            while(i<l)
            {
                int count=i;    // /To Count frequency
                while(i<l && last_string[i]==last_string[count])
                {
                    count++;
                }
                
                ans+=to_string(count-i)+last_string[i];
                i=count;
            }
        }
        return ans;
    }
};