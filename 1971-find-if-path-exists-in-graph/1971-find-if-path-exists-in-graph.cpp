class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>mp;
        for(auto i:edges)
        {
            vector<int>temp=i;
            int u=temp[0];
            int v=temp[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<bool> visited(n,false);
        queue<int>q;
        q.push(source);
        visited[source]=true;
        while(!q.empty())
        {
            int v=q.front();
            q.pop();
            vector<int>temp=mp[v];
                for(int i=0;i<temp.size();i++)
                {
                    int vertex=temp[i];
                    if(visited[vertex]==false)
                    {
                        visited[vertex]=true;
                        q.push(vertex);
                    }
                }

        }
        return visited[destination];
    }
};