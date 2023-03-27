class Solution {
    // Using Memoization
    int temp[201][201];
    int SolveMemoization(vector<vector<int>>& grid,int i,int j,int m,int n)
    {
        if(i==m-1 && j==n-1)    //last cell(destination) par hain,toh return kar denge
            return grid[i][j];
        
        if(temp[i][j]!=-1)  //agar already clculated hai,toh use hi return kar denge
            return temp[i][j];
        //nahin toh,temp mein store karvate hue chalenge
        
        if(i==m-1)  //Last Row can only go Right
            return temp[i][j]=grid[i][j]+SolveMemoization(grid,i,j+1,m,n);
        
        else if(j==n-1) //Last Column can only go Down
            return temp[i][j]=grid[i][j]+SolveMemoization(grid,i+1,j,m,n);
        
        else    // can either go right or down
            return temp[i][j]=grid[i][j]+min(SolveMemoization(grid,i,j+1,m,n),SolveMemoization(grid,i+1,j,m,n));
    }
    // Using Recursion
    // int solveRec(vector<vector<int>>& grid,int i,int j,int m,int n)
    // {
    //     if(i==m-1 && j==n-1)
    //         return grid[i][j];
    //     if(i==m-1)  //Last Row can only go Right
    //         return grid[i][j]+solveRec(grid,i,j+1,m,n);
    //     else if(j==n-1) //Last Column can only go Down
    //         return grid[i][j]+solveRec(grid,i+1,j,m,n);
    //     else    // can either go right or down
    //         return grid[i][j]+min(solveRec(grid,i,j+1,m,n),solveRec(grid,i+1,j,m,n));
    // }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();  //Row
        int n=grid[0].size();   //Column
        // return solveRec(grid,0,0,m,n);  -> recursion 
        memset(temp,-1,sizeof(temp));
        return SolveMemoization(grid,0,0,m,n);
    }
};