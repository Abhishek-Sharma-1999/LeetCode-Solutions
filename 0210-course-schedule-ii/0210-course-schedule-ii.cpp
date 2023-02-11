class Solution {
public:
    vector<int> topologicalSort(unordered_map<int,vector<int>> &adj,int &numCourses,vector<int> &indegree)
    {
        queue<int> q;
        vector<int> result;
        int count=0;    //for checking we have completed all the courses or not
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                result.push_back(i);
                q.push(i);
                count++;
            }
        }
        
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            
            for(int v:adj[u])
            {
                indegree[v]--;
                
                if(indegree[v]==0)
                {
                    result.push_back(v);
                    q.push(v);
                    count++;
                }
            }
        }
        
        if(count==numCourses)
            return result;
        
        return {};  //we had a cycle and we couldn't complete all the courses
    }
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int>indegree(numCourses,0);
        
        for(auto &vec:prerequisites)
        {
            int a=vec[0];
            int b=vec[1];
            adj[b].push_back(a);
            indegree[a]++;
        }                                                   
        
        return topologicalSort(adj,numCourses,indegree);
    }
};