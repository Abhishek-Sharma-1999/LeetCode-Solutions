//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
    bool check(int num)
    {
        int temp=num;
        int ans=0,rev=0,rem=0;
        while(temp!=0)
        {
            rem=temp%10;
            ans=(ans*10)+rem;
            temp=temp/10;
        }
        if(ans==num)
            return true;
            
        return false;    
    }
public:
    int PalinArray(int a[], int n)
    {
    	for(int i=0;i<n;i++)
    	{
    	    if(!check(a[i]))
    	    {
    	        return false;
    	    }
    	}
    	return true;
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
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends