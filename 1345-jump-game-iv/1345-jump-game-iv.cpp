class Solution {
public:
    int minJumps(vector<int>& arr) {
        // SIMPLE BFS
        int n=arr.size();
        unordered_map<int,vector<int>>mp;
        vector<bool>visited(n,false);
        // storing elements and their index in graph
        for(int i=0;i<n;i++)
        {
            mp[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);  //we will insert indexes in queue
        visited[0]=true;
        int steps=0;
        
        while(!q.empty())
        {
            int Size=q.size();
            
            while(Size--)
            {
                int curr=q.front();
                q.pop();
                
                int left=curr-1;
                int right=curr+1;
                
                if(curr==n-1)
                    return steps;
                
                if(left>=0 && !visited[left])
                {
                    q.push(left);
                    visited[left]=true;
                }
                
                if(right<n && !visited[right])
                {
                    q.push(right);
                    visited[right]=true;
                }
                
                for(int index:mp[arr[curr]])
                {
                    if(!visited[index])
                    {
                        q.push(index);
                        visited[index]=true;
                    }
                }
                mp.erase(arr[curr]);
            }
            steps++;
        }
        return -1;
    }
};