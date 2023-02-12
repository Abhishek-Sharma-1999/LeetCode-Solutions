class Solution {
public:
    // 0-Not coloured   1-Red   -1-Blue
    bool check(vector<vector<int>>& graph,vector<int> &color,int start)
    {
        color[start]=1;
        queue<int> q;
        q.push(start);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            
            for(int v:graph[u])
            {
                if(color[v]==0)
                {
                    // Assigning color to it's neighbours
                    color[v]=-color[u];
                    q.push(v);
                }
                else if(color[v]==color[u]) // It's neighbour has already been coloured with same color
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,0);
        for(int i=0;i<n;i++)
        {
            if(color[i]==0)
            {
                if(check(graph,color,i)==false)
                    return false;
            }
        }
        return true;
    }
};