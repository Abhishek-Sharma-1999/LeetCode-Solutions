//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		int top=0,bottom=n-1,left=0,right=m-1;
 		while(top<=bottom && left<=right)
 		{
 		    for(int i=left;i<=right;i++)        // top -> left to right
     		{
     		    k--;
     		    if(k==0)
     		    {
     		        return a[top][i];
     		    }
     		}
     		top++;
     		
     		for(int i=top;i<=bottom;i++)    // right -> top to bottom
     		{
     		    k--;
     		    if(k==0)
     		    {
     		        return a[i][right];
     		    }
     		}
     		right--;
     		
     		for(int i=right;i>=left;i--)       // bottom -> right to left
     		{
     		    k--;
     		    if(k==0)
     		    {
     		        return a[bottom][i];
     		    }
     		}
     		bottom--;
     		
     		for(int i=bottom;i>=top;i--)    // left -> bottom to top
     		{
     		    k--;
     		    if(k==0)
     		    {
     		        return a[i][left];
     		    }
     		}
     		left++;
 		}
 		return 0;
 		
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends