class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int total=row*col;
        int count=0;
        int startingrow=0;
        int endingrow=row-1;
        int startingcol=0;
        int endingcol=col-1;
        vector<int>ans;
        while(count<total)
        {
            // StartingRow
            for(int i=startingcol;i<=endingcol && count<total;i++)
            {
                ans.push_back(matrix[startingrow][i]);
                count++;
            }
            startingrow++;
            
            //Ending Column
            for(int i=startingrow;i<=endingrow && count<total;i++)
            {
                ans.push_back(matrix[i][endingcol]);
                    count++;
            }
            endingcol--;
            
            //Ending Row
            for(int i=endingcol;i>=startingcol && count<total;i--)
            {
                ans.push_back(matrix[endingrow][i]);
                count++;
            }
            endingrow--;
            
            // Starting Column
            for(int i=endingrow;i>=startingrow && count<total;i--)
            {
                ans.push_back(matrix[i][startingcol]);
                count++;
            }
            startingcol++;
        }
        return ans;
    }
};