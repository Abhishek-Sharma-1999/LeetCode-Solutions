//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int i=0,j=0,k=0;
            vector<int> ans;
            int prev1=INT_MIN,prev2=INT_MIN,prev3=INT_MIN;
            while(i<n1 && j<n2 && k<n3)
            {
                while(i<n1 && A[i]==prev1)
                {
                    i++;
                }
                while(j<n2 && B[j]==prev2)
                {
                    j++;
                }
                while(k<n3 && C[k]==prev3)
                {
                    k++;
                }
                if(A[i]==B[j] && B[j]==C[k])
                {
                    ans.push_back(A[i]);
                    prev1=A[i];
                    prev2=B[j];
                    prev3=C[k];
                    i++;
                    j++;
                    k++;
                }
                else if(A[i]<B[j])
                {
                    prev1=A[i];
                    i++;
                }
                else if(B[j]<C[k])
                {
                    prev2=B[j];
                    j++;
                }
                else
                {
                    prev3=C[k];
                    k++;
                }
            }
            return ans;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends