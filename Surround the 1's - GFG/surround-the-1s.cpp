//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int ans=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]==1)
                {
                    int count=0;
                    if(i+1<row && matrix[i+1][j]==0)    //Down
                        count++;
                    if(i-1>=0 && matrix[i-1][j]==0)    //Up
                        count++;
                    if(j+1<col && matrix[i][j+1]==0)    //Right
                        count++;
                    if(j-1>=0 && matrix[i][j-1]==0)     //Left
                        count++;
                    if((i+1<row && j+1<col) && matrix[i+1][j+1]==0)  //Bottom-Right
                        count++;
                    if((i+1<row && j-1>=0) && matrix[i+1][j-1]==0)  //Bottom-Left
                        count++;
                    if((i-1>=0 && j-1>=0) && matrix[i-1][j-1]==0)   //Top-Left
                        count++;
                    if((i-1>=0 && j+1<col) && matrix[i-1][j+1]==0)    //Top-Right
                        count++;    
                    if(count!=0 && count%2==0)
                        ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends