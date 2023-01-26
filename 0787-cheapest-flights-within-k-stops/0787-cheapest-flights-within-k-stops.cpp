class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n,INT_MAX);
        unordered_map<int,vector<pair<int,int>>> adj;
        for(vector<int> &vec:flights)
        {
            int u=vec[0];
            int v=vec[1];
            int cost=vec[2];
            
            adj[u].push_back({v,cost});
        }
        
        // BFS
        queue<pair<int,int>>q;
        q.push({src,0});
        distance[src]=0;
        
        int steps=0;    //k -> ke liye,ki hum source aur destination ke beech kitni baar ruk sakte hai
        
        while(!q.empty()&&steps<=k)
        {
            int Size=q.size();  //queue mein itne elements hai,unhe process karne ke liye
            while(Size--)
            {
                int u=q.front().first;
                int D_cost=q.front().second;
                q.pop();
                
                for(pair<int,int> &p:adj[u])    //same like for(int &v:adj[u])
                {
                    int v=p.first;
                    int Cost=p.second;
                    
                    if(distance[v]>D_cost+Cost){
                        distance[v]=D_cost+Cost;
                        q.push({v,D_cost+Cost});
                    }
                }
                
            }
            steps++;
        }
        
        return distance[dst]==INT_MAX?-1:distance[dst];
        
    }
};