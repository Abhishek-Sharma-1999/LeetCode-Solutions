class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp;
        vector<int>indegree(numCourses,0);
        for(auto &vec:prerequisites)
        {
            int a=vec[0];
            int b=vec[1];
            mp[b].push_back(a);
            indegree[a]++;
        }
        vector<int>res;
        int count=0;
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                count++;
                res.push_back(i);
            }
        }
        // BFS
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int &v:mp[u])
            {
                indegree[v]--;
                if(indegree[v]==0)
                {
                    q.push(v);
                    count++;
                    res.push_back(v);
                }
            }
        }
        
        if(count==numCourses)
            return 1;
        return 0;
    }
};