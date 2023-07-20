//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       unordered_map<char,int>mp;
       for(int i=0;i<S.length();i++)    //pehle map mein store krayenge
       {
           mp[S[i]]++;
       }
       char ans='$';    //agar koi answer nahin mila tohye return krana hai
       for(char i:S) // string ko traverse karenge, na ki map ko aur string ke jis character par abhi hain,uska count map mein 1 hai toh use apne answer mein store kra lenge
       {
           if(mp[i]==1)
           {
               ans=i;
               break;
           }
       }
       return ans;
       
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends