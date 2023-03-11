//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // unordered_map<int,int> mp;
        // vector<int> ans;
        // for(int i=0;i<n;i++)
        // {
        //     mp[arr[i]]++;
        //     if(mp[arr[i]]>1 && mp[arr[i]]<3)
        //     {
        //         ans.push_back(arr[i]);
        //     }
        // }
        // if(ans.size()==0)
        // {
        //     ans.push_back(-1);
        // }
        // sort(ans.begin(),ans.end());
        // return ans;
        
        
        // Approach-2
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int index=arr[i]%n;
            arr[index]+=n;
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]/n>=2)
            {
                ans.push_back(i);
            }
        }
        if(ans.size()==0)
        {
            return {-1};
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends