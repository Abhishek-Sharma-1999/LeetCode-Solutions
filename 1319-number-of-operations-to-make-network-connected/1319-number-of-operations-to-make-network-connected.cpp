class Solution {
public:
    // DFS Code
    void dfs(int src,vector<int> adj[],vector<bool>&visited)
    {
        visited[src]=true;
        for(int i:adj[src])
        {
            if(!visited[i])
            {
                dfs(i,adj,visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int len=connections.size();
        if(len<n-1) //agar edges hi kam hai vertices se,toh connect kar hi nahin paayenge
            return -1;
        vector<int> adj[n]; //For-making graph
        for(auto v:connections)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> visited(n+1,false);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited);
                ans++;
            }
        }
        return ans-1;
    }
};