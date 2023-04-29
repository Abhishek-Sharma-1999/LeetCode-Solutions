class Solution {
    vector<int> topologicalSort(unordered_map<int,vector<int>> &mp,int numCourses,vector<int> &indegree)
    {
        queue<int>q;
        vector<int>res;
        int count=0;
        // jinki indegree 0 hai, unhe queue mein daal denge
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                count++;
                res.push_back(i);
            }
        }
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int &v:mp[u])
            {
                indegree[v]--;
                if(indegree[v]==0)
                {
                    count++;
                    q.push(v);
                    res.push_back(v);
                }
                    
            }
        }
        if(numCourses==count)
            return res;
        return {};
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>mp;
        vector<int>indegree(numCourses,0);
        // Making ajjacency list and indegree
        for(auto &vec:prerequisites)
        {
            int a=vec[0];
            int b=vec[1];
            mp[b].push_back(a);
            indegree[a]++;
        }
        return topologicalSort(mp,numCourses,indegree);
    }
};