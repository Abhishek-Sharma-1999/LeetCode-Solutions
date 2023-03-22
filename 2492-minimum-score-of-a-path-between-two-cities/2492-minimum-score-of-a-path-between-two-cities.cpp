class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // Simple BFS/DFS karenge aur apna answer nikal lenge
        int ans=INT_MAX;
        vector<vector<pair<int,int>>> gr(n+1);  //Making a Graph
        for(auto i:roads)
        {
            gr[i[0]].push_back({i[1],i[2]});  // 1->{2,9}
            gr[i[1]].push_back({i[0],i[2]});   // 2-{1,9} //Bi-directional roads hai,given hai
        }
        // Simple BFS
        vector<bool> visited(n+1,false);
        queue<int>q;
        q.push(1);
        visited[1]=true;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto [v,dis]:gr[u])
            {
                ans=min(ans,dis);
                if(visited[v]==false)   //Not Visited
                {
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};