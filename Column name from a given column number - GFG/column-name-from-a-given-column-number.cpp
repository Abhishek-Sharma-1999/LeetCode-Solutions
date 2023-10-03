//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        string s="ZABCDEFGHIJKLMNOPQRSTUVWXY";
        string ans="";
        while(n>0)
        {
            int rem=n%26;
            ans=s[rem]+ans;
            if(rem==0)
            {
                rem=26;
            }
            n=n-rem;
            n=n/26;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends