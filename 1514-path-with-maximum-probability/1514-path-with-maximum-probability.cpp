class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double>res(n,0.0);
        res[start]=1.0;   //start se start jaane ki probability 100% toh 1 
        unordered_map<int,vector<pair<int,double>>> adj;   //adjacency list {u->{v,probability}}
        for(int i=0;i<edges.size();i++)    //making adjacency list
        {
            int u=edges[i][0];
            int v=edges[i][1];
            double probability=succProb[i];
            adj[u].push_back({v,probability});
            adj[v].push_back({u,probability});
        }
        priority_queue<pair<double,int>>pq;    //max-heap   {probability,node}
        pq.push({res[start],start});
        while(!pq.empty())
        {
            int u=pq.top().second;  //current_node
            double prob=pq.top().first; //probability of current_node
            pq.pop();
            for(auto &temp:adj[u])
            {
                int v=temp.first;   //neighbour node
                double current_probability=temp.second; //probability of neighbour node
                if(prob*current_probability>res[v])
                {
                    res[v]=prob*current_probability;
                    pq.push({res[v],v});
                }
            }
        }
        return res[end];
    }
};