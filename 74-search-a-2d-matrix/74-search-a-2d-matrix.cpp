class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0)
            return false;
        int m=matrix.size();    //Row No.
        int n=matrix[0].size(); // Column No.
        
        int low=0;
        int high=(m*n)-1;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(matrix[mid/n][mid%n]==target)
                return true;
            else if(matrix[mid/n][mid%n]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return false;
    }
};