class Solution {
public:
    void DFS(int ancestor,unordered_map<int,vector<int>> &adj,int currNode,vector<vector<int>>& result)
    {
        for(int &neighbour:adj[currNode])
        {
            if(result[neighbour].empty() || result[neighbour].back()!=ancestor)
            {
                result[neighbour].push_back(ancestor);
                DFS(ancestor,adj,neighbour,result);
            }

        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto &vec:edges)
        {
            int a=vec[0];
            int b=vec[1];
            //a -> b
            adj[a].push_back(b);    
        }
        vector<vector<int>> result(n);
        for(int i=0;i<n;i++)
        {
            int ancestor=i;
            DFS(ancestor,adj,i,result);
        }
        return result;
    }
};