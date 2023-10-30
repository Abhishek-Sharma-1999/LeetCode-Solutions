//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	// Brute Force (Approach-1)
        // 	long long int sum=0;
        // 	for(int i=0;i<n;i++)
        // 	{
        // 	    for(int j=i+1;j<n;j++)
        // 	    {
        // 	        sum+=(arr[i]^arr[j]);
        // 	    }
        // 	}
        // 	return sum;
        
        // Approach-2 (Optimised)
        long long int ans=0;
        for(int i=0;i<32;i++)
        {
            long long int zero_count=0,one_count=0;
            for(int j=0;j<n;j++)
            {
                if(arr[j]%2==0)
                {
                    zero_count++;
                }
                else
                {
                    one_count++;
                }
                arr[j]=arr[j]/2;
            }
            ans+=(zero_count*one_count)*(1<<i);
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends