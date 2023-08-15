//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        int count_zero=0;
        int count_one=0;
        int flip=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                count_zero++;
            }
            else
            {
                count_zero--;
                count_one++;
            }
            flip=max(flip,count_zero);
            if(count_zero<0)
            {
                count_zero=0;
            }
        }
        return flip+count_one;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends