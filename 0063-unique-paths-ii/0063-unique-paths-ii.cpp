class Solution {
public:
    int solve(int i,int j,int row,int col,vector<vector<int>>& obstacleGrid)
    {
        if(i>=row || j>=col  || obstacleGrid[i][j]==1)
        {
            return 0;
        }
        if(i==row-1 && j==col-1)
        {
            return 1;
        }
        int down=solve(i+1,j,row,col,obstacleGrid);
        int right=solve(i,j+1,row,col,obstacleGrid);
        return down+right;
    }
    int solve_memoization(int i,int j,int row,int col,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp)
    {
        if(i>=row || j>=col  || obstacleGrid[i][j]==1)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(i==row-1 && j==col-1)
        {
            return 1;
        }
        int down=solve_memoization(i+1,j,row,col,obstacleGrid,dp);
        int right=solve_memoization(i,j+1,row,col,obstacleGrid,dp);
        return dp[i][j]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        return solve_memoization(0,0,row,col,obstacleGrid,dp);
    }
};