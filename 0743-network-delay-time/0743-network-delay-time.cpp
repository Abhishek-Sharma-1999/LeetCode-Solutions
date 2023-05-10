class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Dijkstra Algorithm
        
        // Making Adjacency List
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &vec:times)
        {
            int u=vec[0];
            int v=vec[1];
            int w=vec[2];
            adj[u].push_back({v,w});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;  //{Distance,Node}
        vector<int>result(n+1,INT_MAX);
        result[k]=0;
        pq.push({0,k});
        
        while(!pq.empty())
        {
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &vec:adj[node])
            {
                int adjNode=vec.first;
                int dist=vec.second;
                
                if(d+dist<result[adjNode])
                {
                    result[adjNode]=d+dist;
                    pq.push({d+dist,adjNode});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,result[i]);
        }
        return ans==INT_MAX ? -1 : ans;
    }
};