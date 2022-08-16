class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans; // For Storing Answer
        int row=matrix.size();
        int col=matrix[0].size();
        int total =row*col;
        int count=0;
        
        int startingRow=0;
        int endingRow=row-1;
        int startingCol=0;
        int endingCol=col-1;
        
        while(count<total)
        {
            // Starting Row
            for(int i=startingCol;i<=endingCol && count<total;i++)
            {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;
            
            // Ending Col
            for(int i=startingRow;i<=endingRow && count<total;i++)
            {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;
            
            // Last Row
            for(int i=endingCol;i>=startingCol && count<total;i--)
            {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;
            
            // StartingCol
            for(int i=endingRow;i>=startingRow && count<total;i--)
            {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
            
        }
        return ans;
    }
};