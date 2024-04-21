class Solution {
public:
    bool check(unordered_map<int,vector<int>>& adj,int node,int destination,vector<bool>& visited){
        if(node==destination){
            return true;
        }
        if(visited[node]){
            return false;
        }
        visited[node]=true;
        for(auto &it:adj[node]){
            if(check(adj,it,destination,visited)){
                return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>adj;
        for(vector<int> &vec:edges){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>visited(n,false);
        return check(adj,source,destination,visited);
    }
};