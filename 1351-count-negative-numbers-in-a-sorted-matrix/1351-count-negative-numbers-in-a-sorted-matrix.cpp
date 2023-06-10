class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // Brute Force - O(n)
        int count=0;
        int rows=grid.size(),col=grid[0].size();
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]<0)
                    count++;
            }
        }
        return count;
    }
};