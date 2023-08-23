//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool dfs(int i,int j,vector<vector<char>>grid, string word,int index,int row,int col,int x1,int x2)
{
    index++;
    if(index==word.size()){
        return true;
    }
    int new_i=i+x1;
    int new_j=j+x2;
    if(new_i >=0 && new_j>=0 && new_i<row && new_j<col && grid[new_i][new_j]==word[index])
    {
        return dfs(new_i,new_j,grid,word,index,row,col,x1,x2);
    }
    return false;
}
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    vector<vector<int>>res;
	    int row=grid.size();
	    int col=grid[0].size();
	    int dir_i[]={1,0,0,-1,1,-1,-1,1};
	    int dir_j[]={0,1,-1,0,1,1,-1,-1};
	    for(int i=0;i<row;i++)
	    {
	        for(int j=0;j<col;j++)
	        {
	            if(grid[i][j]==word[0])
	            {
	                for(int k=0;k<8;k++)
	                {
	                    if(dfs(i,j,grid,word,0,row,col,dir_i[k],dir_j[k])){
	                        res.push_back({i,j});
	                        break;
	                    }
	                    
	                }
	            }
	        }
	    }
	    return res;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends