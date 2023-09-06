//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    void dfs(vector<int>adj[],int u,vector<bool>& visited)
    {
        visited[u]=true;
        for(int v:adj[u])
        {
            if(!visited[v]){
                dfs(adj,v,visited);
            }
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<bool>visited(V,false);
	    int ans=-1;
	    for(int i=0;i<V;i++){
	        if(!visited[i])
	        {
	            dfs(adj,i,visited);
	            ans=i;
	        }
	    }
	    
	    fill(visited.begin(),visited.end(),false);
	    dfs(adj,ans,visited);
	    
	    for(bool v:visited)
	    {
	        if(!v){
	            return -1;
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
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends