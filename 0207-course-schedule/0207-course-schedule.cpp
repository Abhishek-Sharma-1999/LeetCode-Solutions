class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;  //Adjacency List
        vector<int>indegree(numCourses,0);
        for(auto &vec:prerequisites)
        {
            int a=vec[0];
            int b=vec[1];
            // b->a (pehle 'b' phir 'a' , b se a ki taraf arrow ja rha hai)
            adj[b].push_back(a);
            indegree[a]++;  //arrow a ki taraf,jaa rha hai toh 'a' ki indegree increase hogi
        }
        queue<int>q; 
        int count=0;    //track rakhne ke liye,ki kitne courses visit kiye hain
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0){  // jis ki indegree 0 hogi,use queue mein daal denge
                q.push(i);
                count++;
            }
        }
        // Normal BFS
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int &v:adj[u])
            {
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    count++;
                }
            }
        }
        if(count==numCourses)   //saare course visite kar liye,toh true return kar denge
            return true;    //nahin toh false return kar denge
        return false;
    }
};