//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    vector<int>adj[N];
	    vector<int>indegree(N,0);
	    for(auto vec:prerequisites)
	    {
	        // b->a
	        indegree[vec.first]++;
	        adj[vec.second].push_back(vec.first);
	    }
	    queue<int>q;
	    int count=0;
	    for(int i=0;i<N;i++)
	    {
	        if(indegree[i]==0){
	            q.push(i);
	            count++;
	        }
	    }
	   
	    while(!q.empty())
	    {
	        int u=q.front();
	        q.pop();
	        for(auto v:adj[u])
	        {
	            indegree[v]--;
	            if(indegree[v]==0){
	                q.push(v);
	                count++;
	            }
	        }
	    }
	    for(int i:indegree)
	    {
	        if(i!=0)    return 0;
	    }
	    return 1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends