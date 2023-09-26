//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
       int n=arr.size();
       vector<vector<int>>ans;
       sort(arr.begin(),arr.end());
       for(int i=0;i<n;i++)
       {
           if(i>0 && arr[i]==arr[i-1])  //for avoiding duplicates
           {
               continue;
           }
           for(int j=i+1;j<n;j++)
           {
               if(j>i+1 && arr[j]==arr[j-1])
               {
                   continue;
               }
               int start=j+1;
               int end=n-1;
               while(start<end)
               {
                   long long sum=arr[i]+arr[j]+arr[start]+arr[end];
                   if(sum==k)
                   {
                       vector<int>temp={arr[i],arr[j],arr[start],arr[end]};
                       ans.push_back(temp);
                       start++;
                       end--;
                       
                       //skip the duplicates
                       while(start<end && arr[start]==arr[start-1])
                            start++;
                        
                        while(start<end && arr[end]==arr[end+1])
                            end--;
                   }
                   else if(sum<k)
                   {
                       start++;
                   }
                   else
                   {
                       end--;
                   }
               }
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends