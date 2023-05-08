class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        // Approach -1
        // int row=mat.size();
        // int col=mat[0].size();
        // int sum=0;
        // for(int i=0;i<row;i++)
        // {
        //     for(int j=0;j<col;j++)
        //     {
        //         if(i==j)
        //         {   //primary diagonal
        //             sum+=mat[i][i];
        //         }
        //         else if(i+j==row-1)
        //         {
        //             sum+=mat[i][j];
        //         }
        //     }
        // }
        // return sum;
        
        // Approach-2 O(n)
        int m=mat.size();
        int sum=0;
        for(int i=0;i<m;i++){
            sum+=mat[i][i];
            sum+=mat[i][m-i-1];
        }
        if(m%2!=0)  //odd
            sum-=mat[m/2][m/2];
        return sum;
    }
};