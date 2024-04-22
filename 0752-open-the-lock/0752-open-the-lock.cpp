class Solution {
public:
    void fillNeighbours(queue<string> &q,string &curr,unordered_set<string> &st)
    {
        for(int i=0;i<4;i++)
        {
            char ch=curr[i];
            char inc=ch=='9' ? '0' : ch+1;
            char dec=ch=='0' ? '9' : ch-1;
            curr[i]=inc;
            //agar vo dead-end mein nahin hai, toh use queue mein daal denge, saath mein
            // jo string bani hai, use bhi deadend vaale list mein daal denge, taaki
            // agar dobara string par aa gaye, toh dobara vahi sab processing na kare
            // to avoid infinite loop
            if(!st.count(curr))
            {
                st.insert(curr);
                q.push(curr);
            }
            curr[i]=dec;
            if(!st.count(curr))
            {
                st.insert(curr);
                q.push(curr);
            }
            //jo vhanges kare the , us character par vo dobara revert back kar diye
            curr[i]=ch;
        }
    }
    int openLock(vector<string>& deadends, string target) {
        string start="0000";
        unordered_set<string>st(deadends.begin(),deadends.end());
        if(st.count(start))    //starting state hi deadend mein fsa hua hai
        {
            return -1;
        }
        queue<string>q;
        q.push(start);
        int level=0;
        while(!q.empty())
        {
            int n=q.size();
            //n level ke items hain queue mein, hme sab ko process karna hai
            while(n--)
            {
                string curr=q.front();
                q.pop();
                if(curr==target)
                {
                    return level;
                }
                fillNeighbours(q,curr,st);
            }
            //matlab ek level travere ho gya, toh level ka count bda denge
            level++;    
        }
        return -1;
    }
};