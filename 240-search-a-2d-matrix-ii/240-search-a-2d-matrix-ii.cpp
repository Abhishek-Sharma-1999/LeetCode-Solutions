class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0;    //Row
        int j=matrix[0].size()-1;   //Column
        // First Row-Last Column (Element)
        
        while(i>=0 && i<matrix.size() && j>=0 && j<matrix[0].size())
        {
            if(matrix[i][j]==target)
                return true;
            else if(matrix[i][j]>target)
                j--;
            else
                i++;
        }
        return false;
    }
};