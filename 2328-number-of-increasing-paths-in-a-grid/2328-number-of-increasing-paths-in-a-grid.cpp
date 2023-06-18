class Solution {
public:
    long long int MOD=1e9+7;
    int m,n;
    vector<vector<int>> directions={
            {-1,0},
        {0,-1},{0,1},
            {1,0}
    };
    bool isSafe(int i,int j)
    {
        return (i>=0 && i<m && j>=0 && j<n);    
    }
    int dp[1001][1001];
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        int answer=1;   //grid[i][j],khud mein increasing path toh hai hii
        for(auto &dir:directions)
        {
            int _i=i+dir[0];
            int _j=j+dir[1];
            if(isSafe(_i,_j)&&grid[_i][_j]<grid[i][j])
            {
                answer=(answer+dfs(grid,_i,_j))%MOD;
            }
        }
        return dp[i][j]=answer;
    }
    int countPaths(vector<vector<int>>& grid) {
        m=grid.size();  //rows
        n=grid[0].size();   //columns
        int result=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                result=(result+dfs(grid,i,j))%MOD;
            }
        }
        return result;
    }
};