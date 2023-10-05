//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  long long solve(string s, int k)
  {
    //   unordered_map<char,int>mp;
    int mp[26]={0};
      int i=0,j=0;
      long long ans=0;
      int distinct=0;
      while(j<s.size())
      {
          mp[s[j]-'a']++;
          if(mp[s[j]-'a']==1){
              distinct++;
          }
          while(distinct>k)
          {
              if(mp[s[i]-'a']==1)
              {
                  distinct--;
                  mp[s[i]-'a']--;
              }
              else{
                  mp[s[i]-'a']--;
              }
              i++;
          }
          ans=ans+(j-i+1);
          j++;
      }
      return ans;
  }
    long long int substrCount (string s, int k) {
    	return solve(s,k)-solve(s,k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends