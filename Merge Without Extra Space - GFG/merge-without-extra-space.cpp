//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // Brute Force
            int i=0,j=0,index=0;
            long long arr3[m+n];    //using extra space
            while(i<n && j<m)
            {
                if(arr1[i]<=arr2[j])
                {
                    arr3[index]=arr1[i];
                    i++;
                    index++;
                }
                else{
                    arr3[index]=arr2[j];
                    j++;
                    index++;
                }
                
            }
            while(i<n)
            {
                arr3[index++]=arr1[i++];
            }
            while(j<m)
            {
                arr3[index++]=arr2[j++];
            }
            
            for(int i=0;i<n+m;i++)
            {
                if(i<n)
                    arr1[i]=arr3[i];
                else
                    arr2[i-n]=arr3[i];
            }
        } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends