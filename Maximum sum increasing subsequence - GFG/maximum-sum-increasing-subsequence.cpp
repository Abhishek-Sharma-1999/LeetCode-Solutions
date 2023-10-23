//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int>sum(n,0);
	    for(int i=0;i<n;i++)
	    {
	        for(int j=i-1;j>=0;j--)
	        {
	            if(arr[i]>arr[j])
	            {
	                sum[i]=max(sum[i],sum[j]);
	            }
	        }
	        sum[i]+=arr[i];
	    }
	    return *max_element(sum.begin(),sum.end());
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends