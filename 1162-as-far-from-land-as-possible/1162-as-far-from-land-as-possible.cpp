class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                }
            }
        }
        
        if(q.empty() || q.size()==n*n) //queue empty hai ya saare jagah sirf land(1) hi hai
            return -1;
        
        int distance=-1;
        vector<pair<int,int>> dirs={{0,-1},{0,1},{-1,0},{1,0}};
        // BFS
        while(!q.empty())
        {
            int Size=q.size();
            while(Size--)
            {
                auto [x,y]=q.front();
                q.pop();
                for(auto [dx,dy]:dirs)
                {
                    int i=x+dx,j=y+dy;
                    if(i>=0 && i<n && j>=0 && j<n && grid[i][j]==0)
                    {
                        grid[i][j]=1;
                        q.push({i,j});
                    }
                }
            }
            distance++;
        }
        return distance;
    }
};