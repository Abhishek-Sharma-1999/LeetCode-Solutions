class Solution {
public:
    int countPrimes(int n) {
        if(n<=1)
            return 0;
        vector<bool>visited(n+1,true);
        visited[0]=false;
        visited[1]=false;
        for(int i=2;i*i<n;i++)
        {
            if(visited[i])
            {
                for(int j=i*i;j<n;j+=i)
                {
                    visited[j]=false;
                }
            }
                
        }
        
        int ans=0;
        for(int i=2;i<n;i++)
        {
            if(visited[i])
                ans++;
        }
        
        return ans;
        
    }
};