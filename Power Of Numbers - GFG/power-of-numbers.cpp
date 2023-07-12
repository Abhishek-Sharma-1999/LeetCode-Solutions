//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    //You need to complete this fucntion
    long long MOD=1e9+7;
    long long power(int N,int R)
    {
       if(R==0)
            return 1;
        if(N==0)
            return 0;
        if(R%2==0) {    //even
            long long ans=power(N,R/2);         // 2^8  => (2^4) x (2^4)
            return ((ans)%MOD*(ans)%MOD)%MOD;
        }
        else{   //odd
            long long ans=power(N,(R-1)/2);     // 2^9 => (2^4) x (2^4) x 2
            return ((ans)%MOD*(ans)%MOD * N)%MOD;
        }
       return N*power(N,R-1);
        
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends