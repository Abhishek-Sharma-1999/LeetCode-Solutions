//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
// void prime(vector<bool>& isPrime,int N)
// {
//     isPrime[0]=false;
//     isPrime[1]=false;
//     for(int i=2;i<=N;i++)
//     {
//         if(isPrime[i]==true)
//         {
//             // cout<<i<<"  ";
//             for(int j=2*i;j<=N;j=j+i)
//             {
//                 isPrime[j]=false;
//             }
//         }
//     }
// }
    long long int largestPrimeFactor(int N){
        // long long ans=0;
        // vector<bool>isPrime(N+1,true);
        // prime(isPrime,N);
        // for(int i=2;i<=N;i++)
        // {
        //     if(isPrime[i] && N%i==0)
        //     {
        //         // cout<<i<<"      ";
        //         ans=i;
        //     }
        // }
        // return ans;
        
        long long int i=2;
        while(i*i<=N)
        {
            if(N%i==0)
            {
                N=N/i;
            }
            else
            {
                i++;
            }
        }
        return N;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends