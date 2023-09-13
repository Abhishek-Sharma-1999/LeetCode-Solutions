//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int Sum){
        string ans="";
        for(int i=0;i<N;i++)
        {
            if(Sum>=9)
            {
                ans+="9";
                Sum=Sum-9;
            }
            else
            {
                ans+=to_string(Sum);
                Sum=Sum-Sum;
            }
        }
         // N=4,Sum=0 bnana hai,toh 0000, aa jayega,tab is case mein bhi -1 reurn hoga
        if(N>1 && ans[0]=='0'){ 
            return "-1";
        }
        if(Sum==0){
            return ans;
        }
        return "-1";
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends