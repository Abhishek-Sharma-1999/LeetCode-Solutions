class Solution {
    bool isSimilar(string &s1,string &s2)
    {
        int n=s1.length();  //all string length's would be same (Acc. to question)
        int diff=0; //how many characters are diiferent b/w 2 strings
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])
                diff++;
        }
        return (diff==2) || (diff==0);
    }
    
    void DFS(unordered_map<int,vector<int>>& mp,int u,vector<bool>& visited)
    {
        visited[u]=true;
        for(int v:mp[u])
        {
            if(!visited[v])
                DFS(mp,v,visited);
        }
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        unordered_map<int,vector<int>> mp;  //Adjacency List
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(isSimilar(strs[i],strs[j])) //if these strings are similar,we are making adjacency list
                {
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }
        
        // DFS
        vector<bool> visited(n,false);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                DFS(mp,i,visited);
                count++;
            }
        }
        return count;
    }
};