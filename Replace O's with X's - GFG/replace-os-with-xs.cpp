//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void dfs(int row,int col,vector<vector<char>> &mat,int n,int m,char symbol)
{
    if(row<0 || row>=n || col<0 || col>=m || mat[row][col]!='O'){
        return;
    }
    mat[row][col]=symbol;
    dfs(row+1,col,mat,n,m,symbol);
    dfs(row,col+1,mat,n,m,symbol);
    dfs(row-1,col,mat,n,m,symbol);
    dfs(row,col-1,mat,n,m,symbol);
}
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // boundary-vaale "O" k '$' se mark kar denge
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(mat[i][j]=='O')
                    {
                        dfs(i,j,mat,n,m,'$');
                    }
                }
            }
        }
        
        // ab jo beech mein hai,unhe 'X' se mark kar denge
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O')
                {
                    dfs(i,j,mat,n,m,'X');
                }
            }
        }
        
        // vapas se boundary vaalo ko "O" mark kar denge,kunki pehle humne '$' mark kiya tha
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='$')
                {
                    mat[i][j]='O';
                }
            }
        }
        
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends