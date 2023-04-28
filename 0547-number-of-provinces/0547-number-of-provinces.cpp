class Solution {
    void DFS(unordered_map<int,vector<int>>& mp,int u,vector<bool>& visited)
    {
        visited[u]=true;
        for(int &v:mp[u])
        {
            if(!visited[v])
            {
                DFS(mp,v,visited);
            }
        }
    }
public:
    int n;
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();   //size() of matrix ->rows, kitne vertices hain
        unordered_map<int,vector<int>>mp; //adjacency list
        vector<bool>visited(n,false);
        // making adjacency list,from matrix
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }
        //calculating provinces using DFS
        int count=0;    //count of provinces
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                DFS(mp,i,visited);
                count++; //jab vapas aa gaye.matlab koi province nahin mila, toh jo abhi currently mila hai,uska count bda denge
            }
        }
        return count;
    }
};