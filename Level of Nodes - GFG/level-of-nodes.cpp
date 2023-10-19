//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    int visited[V]={0};
	    queue<pair<int,int>>q;
	    q.push({0,0});  //{node,level}, pehle level 0 se start hoga aur node bhi 0 se (given in question)
	    visited[0]=1;
	    while(!q.empty())
	    {
	        int u=q.front().first;
	        int Level=q.front().second;
	        q.pop();
	        if(u==X)
	        {
	            return Level;
	        }
	        for(int v:adj[u])
	        {
	            if(!visited[v])
	            {
	                q.push({v,Level+1});
	                visited[v]=1;
	            }
	        }
	    }
	  return -1;
	}

};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends