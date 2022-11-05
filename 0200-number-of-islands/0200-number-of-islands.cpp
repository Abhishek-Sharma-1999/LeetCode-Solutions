class Solution {
public:
    void Dfs(vector<vector<char>>& grid,int i,int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0')
            return;
        grid[i][j]='0'; //marking current island as water as counting and considering it
        Dfs(grid,i+1,j);
        Dfs(grid,i,j+1);
        Dfs(grid,i-1,j);
        Dfs(grid,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    islands++;
                    Dfs(grid,i,j);
                }
            }
        }
        return islands;
    }
};