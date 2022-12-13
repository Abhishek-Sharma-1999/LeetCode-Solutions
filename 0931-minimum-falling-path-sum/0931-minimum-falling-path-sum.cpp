class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();    //row
        int n=matrix[0].size(); //column
        if(m==1)
        {
            return *min_element(matrix[0].begin(),matrix[0].end());
        }
        else
        {   // we will start traversing from second row(1st index),because first row(0 index) we have all the choices
            // hum add karte hue jaayenge second row se, ki us element tak jaane mein kya cost hai minimum
            // 3 cases banege, ki hum hum 0th column par hain,last coumn par hain ya middle mein kisi column par hain 
            for(int i=1;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(j==0)   
                    {
                        matrix[i][j]=matrix[i][j]+min(matrix[i-1][j],matrix[i-1][j+1]);
                    }
                    else if(j==m-1) //last column
                    {
                        matrix[i][j]=matrix[i][j]+min(matrix[i-1][j],matrix[i-1][j-1]);
                    }
                    else
                    {
                        matrix[i][j]=matrix[i][j]+min(matrix[i-1][j-1],min(matrix[i-1][j],matrix[i-1][j+1]));
                    }
                }
            }
            return *min_element(matrix[m-1].begin(),matrix[m-1].end()); //selecting last element from last row
        }
    }
};