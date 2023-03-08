//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
       sort(arr,arr+n);
       int ans=arr[n-1]-arr[0];
       int maxEle,minEle;
       for(int i=1;i<n;i++)
       {
            maxEle=max(arr[i-1]+k,arr[n-1]-k);
            minEle=min(arr[0]+k,arr[i]-k);
            ans=min(ans,maxEle-minEle);
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends