class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int ans=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    ans=ans+4;
                    
                    if(i+1 < row && grid[i+1][j]==1)    //down neighbour is there
                        ans--;
                    if(i-1 >=0  && grid[i-1][j]==1)    //up neighbour is there
                        ans--;
                    if(j-1>=0  && grid[i][j-1]==1)    //left neighbour is there
                        ans--;
                    if(j+1 <col && grid[i][j+1]==1)    //right neighbour is there
                        ans--;
                }
            }
        }
        return ans;
    }
};