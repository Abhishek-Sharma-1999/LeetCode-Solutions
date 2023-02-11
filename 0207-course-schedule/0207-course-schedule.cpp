class Solution {
public:
    bool topologicalSortCheck(unordered_map<int,vector<int>> &adj,int numCourses,vector<int> &indegree)
    {
        queue<int> q;
        int count=0;    //for count of visited nodes
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                count++;
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int &v:adj[u])
            {
                indegree[v]--;
                if(indegree[v]==0)
                {
                    q.push(v);
                    count++;
                }
            }
        }
        
        if(count==numCourses)    //I was able to visit all nodes(courses)
            return true;
        
        return false;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses,0);
        // making our fraph,through adjacency list
        for(auto vec:prerequisites)
        {
            int a=vec[0];
            int b=vec[1];
            // pehle b karenge,phira (b---> a)  se a arrow ja rha hai
            adj[b].push_back(a);
            // arrow ja rha hai a mein, toh indegree uski bad jaayegi
            indegree[a]++;
        }
        // if cycle is present,not possible
        
        return topologicalSortCheck(adj,numCourses,indegree);
    }
};