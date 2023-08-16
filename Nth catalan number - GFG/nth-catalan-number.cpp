//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    const long long int MOD=1e9+7;
    int findCatalan(int n) 
    {
        if(n==0 || n==1)    return 1;
        vector<long long int>ans(n+1,0);
        ans[0]=1;
        ans[1]=1;
        for(int i=2;i<=n;i++)
        {
            int low=0,high=i-1;
            while(low<i && high>=0)
            {
                ans[i]=(ans[i]+(ans[low]*ans[high])%MOD)%MOD;
                low++;
                high--;
            }
        }
        return ans[n]%MOD;
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends