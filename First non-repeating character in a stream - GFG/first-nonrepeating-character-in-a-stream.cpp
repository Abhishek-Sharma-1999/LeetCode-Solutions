//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		   vector<int>freq(26,0);   //frequency array
		   queue<char>q;
		   string ans;
		   for(int i=0;i<A.length();i++)
		   {
		       freq[A[i]-'a']++;
		       if(freq[A[i]-'a']<=1)
		       {
		           q.push(A[i]);
		       }
		       int flag=0;
		       while(!q.empty())
		       {
		           char x=q.front();    
// jo character abhi queue se nikala hai,agar uski frequency 1 hui toh ans mein daal denge,nahin toh pop kra denge		           
		           if(freq[x-'a']==1)
		           {
		               ans+=x;
		               flag=1;
		               break;
		           }
		           else{
		               q.pop();
		           }
		       }
		       if(q.empty() && flag==0)
		       {
		           ans+='#';
		       }
		   }
		   return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends