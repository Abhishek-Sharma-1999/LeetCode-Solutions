class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size();       //row
        int n=mat[0].size();    // column
        vector<int>rowCount(m,0);
        vector<int>colCount(n,0);
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        //Traversing again and checking if that row and colmn contains 1
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                    continue;
                if(rowCount[i]==1 && colCount[j]==1)
                    ans++;
            }
        }
        return ans;
    }
};