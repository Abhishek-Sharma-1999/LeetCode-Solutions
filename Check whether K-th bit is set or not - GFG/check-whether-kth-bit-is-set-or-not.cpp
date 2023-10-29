//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        // Approach-1
            // for(int i=1;i<=k;i++)
            // {
            //     n=n/2;
            // }
            // return n%2==1;
        
        // Approach-2
        // while(k--)
        // {
        //     n=n>>1; //left-shift in bitwise -> is tarike se hum number ke binary representation (bits) ko traverse karte hain
        // }
        // return (n&1);   //agar us bit ka 1 ka & 1 hai, toh true return hoga, nahin toh false
        
        //One-Liner
        return ((n>>k)&1)==1;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
	int t;
	cin>>t;//taking testcases
	while(t--)
	{
	    long long n;
	    cin>>n;//input n
	    int k;
	    cin>>k;//bit number k
	    Solution obj;
	    if(obj.checkKthBit(n, k))
	        cout << "Yes" << endl;
	    else
	        cout << "No" << endl;
	}
	return 0;
}
// } Driver Code Ends