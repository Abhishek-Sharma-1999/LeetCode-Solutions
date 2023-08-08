//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int gcd(int a,int b)
    {
        if(b==0)
            return a;
        return gcd(b,a%b);    
    }
    int countFractions(int n, int numerator[], int denominator[])
    {
        // Approach-1
            // vector<float>v;
            // for(int i=0;i<n;i++)
            // {
            //     v.push_back(float(numerator[i])/float(denominator[i]));
            // }
            // int count=0;
            // for(int i=0;i<n;i++)
            // {
            //     for(int j=i+1;j<n;j++)
            //     {
            //         if(v[i]+v[j]==1)
            //         {
            //             count++;
            //         }
            //     }
            // }
            // return count;
        //Arrpoach-2    
        map<pair<int,int>,int>mp; //{x,y}-1
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int d=gcd(numerator[i],denominator[i]);
            numerator[i]=numerator[i]/d;
            denominator[i]=denominator[i]/d;
            
            int x=numerator[i];
            int y=denominator[i];
            int z=y-x;
            if(mp.count({z,y}))
            {
                ans=ans+mp[{z,y}];
            }
            mp[{x,y}]++;
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
        int n;
        cin>>n;
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends