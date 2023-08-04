//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
void insert_at_last(stack<int> &St,int x)
{
    if(St.empty())  //jaise hi stack empty ho jaayega,hum apne vaale element ko daal denge
    {
        St.push(x);
        return;
    }
    int temp=St.top();
    St.pop();
    insert_at_last(St,x);
    St.push(temp); //// yhaan par aa gaye,matlab um apne x element ko last mein daal chuke hone,toh jo element abhi stack se nikala tha,use vapas daal denge
}
    void Reverse(stack<int> &St){
        // Approach -1 (Without Recursion ,using vector)
        // vector<int>ans;
        // while(!St.empty())
        // {
        //     ans.push_back(St.top());
        //     cout<<St.top()<<"++++"<<endl;
        //     St.pop();
        // }
        // for(int i=0;i<ans.size();i++)
        // {
        //     St.push(ans[i]);
        // }
        if(St.empty())
        {
            return;
        }
        int temp=St.top();
        St.pop();
        Reverse(St);
        insert_at_last(St,temp);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends