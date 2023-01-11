class Solution {
    private:
    int DFS(unordered_map<int,vector<int>>& adj,int curr,int parent,vector<bool>& hasApple){
        int time=0;
        for(int &child:adj[curr])
        {
            if(child==parent)
                continue;
            int time_from_child=DFS(adj,child,curr,hasApple);
            if(time_from_child || hasApple[child])
            {
                time=time+2+time_from_child;
            }
        }
        return time;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>>adj;  //Adjacency List
        for(auto &vec:edges)
        {
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return DFS(adj,0,-1,hasApple);
    }
};