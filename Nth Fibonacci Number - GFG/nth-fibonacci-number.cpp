//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  const long long int MOD=1000000007;
    int nthFibonacci(int n){
        vector<long long int>ans(n+1);
        ans[0]=0;
        ans[1]=1;
        for(int i=2;i<=n;i++)
        {
            ans[i]=ans[i-1]%MOD+ans[i-2]%MOD;
            
        }
        return ans[n]%MOD;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends