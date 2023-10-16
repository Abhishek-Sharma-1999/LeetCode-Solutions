//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
unordered_map<int, int> mp;
int xa[4] = {1, -1, 0, 0};
int ya[4] = {0, 0, 1, -1};
int p;

int dfs(int x, int y, vector<vector<bool>> &vis, vector<vector<int>> &grid, int key) {
    vis[x][y] = true;
    int count = 1; 

    for (int i = 0; i < 4; i++) 
    {
        int x_ = x + xa[i];
        int y_ = y + ya[i];
        if (x_ >= 0 && x_ < p && y_ >= 0 && y_ < p && !vis[x_][y_] && grid[x_][y_] == 1) {
            count += dfs(x_, y_, vis, grid, key);
        }
    }
    
    grid[x][y] = key; 
    return count;
}

    int largestIsland(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int key=2;
        p=n;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(vis[i][j]==false && grid[i][j]==1){
                   int count=dfs(i,j,vis,grid,key);
                   mp[key]=count;
                   key++;
                       
                   
               }
           }
       }
       int result=-1;
   
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
            
               if(grid[i][j]==0){
                      int res=1;
                      set<int>s;
                   for(int k=0;k<4;k++){
                       int x_=i+xa[k];
                       int y_=j+ya[k];
                       if(x_>=0 && x_<p && y_>=0 &&y_<p){
                           s.insert(grid[x_][y_]);
                       }
                       
                   }
                   for(auto &x:s){
                       res+=mp[x];
                   }
                  
                    result=max(result,res);
               }
           }
       }
       if(result==-1) return n*n;
       return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends