//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool isCycleDFS(vector<int> adj[],int u,vector<bool>& visited,int parent)
    {
        visited[u]=true;
        for(int v:adj[u])
        {
            if(v==parent)   //agar parent hi mil gya,toh aage bad jaayenge aur continue karenge
                continue;
            if(visited[v])  //vo visited hua
                return true;
             //agar visited nahin hai, aur agar aa gya kivo
             if(isCycleDFS(adj,v,visited,u))
             {
                 return true;
             }
        }
        return false;
    }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
       vector<bool> visited(V,false);
       for(int i=0;i<V;i++)
       {
           if(!visited[i] && isCycleDFS(adj,i,visited,-1))
           {
               return true;
           }
       }
       return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends