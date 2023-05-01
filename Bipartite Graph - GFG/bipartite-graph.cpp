//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool isBipartiteDFS(vector<int>adj[],int current_node,int current_color,vector<int>& color)
    {
        color[current_node]=current_color;
        for(int &v:adj[current_node])
        {
            if(color[v]==color[current_node])   //agar jis neighbour par ja rahe hain,aur abhi jis par hain dono ka color same hai,toh false return karenge
            {
                return false;
            }
            if(color[v]==-1)    //abhi visit nahin kiya hai
            {
                int color_of_neighbour=1-current_color;
                // ab ispe DFS maar denge, aur agar vhaan se false aaya toh false return karenge
                if(isBipartiteDFS(adj,v,color_of_neighbour,color)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>color(V,-1);
	    int current_color=0;
	    for(int i=0;i<V;i++)
	    {
	        if(color[i]==-1)    //abhi visit nahin hua,na hi color,toh DFS maarenge
	        {
	            if(isBipartiteDFS(adj,i,current_color,color)==false)
	            {
	                return false;
	            }
	        }
	    }
	    return true;
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
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends