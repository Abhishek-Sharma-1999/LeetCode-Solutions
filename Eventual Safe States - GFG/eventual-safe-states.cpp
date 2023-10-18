//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int indegree[V]={0};
        vector<int>adjRev[V];   //Adjacency List in Reverse
        for(int u=0;u<V;u++)
        {
            for(auto v:adj[u])  // 0 ->1,2,3
            {
                adjRev[v].push_back(u); //1 ->0
                indegree[u]++;  //for loop vaala
            }
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<V;i++)    //jinki indegree 0 hai, unhe queue mein daal denge
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(auto v:adjRev[u])
            {
                indegree[v]--;
                if(indegree[v]==0)
                {
                    q.push(v);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends