//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        sort(A.begin(),A.end(),greater<int>());
        sort(B.begin(),B.end(),greater<int>());
        vector<int>result;
        priority_queue<int,vector<int>,greater<int>>pq; //Min-heap
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                int sum=A[i]+B[j];
                if(pq.size()<K)
                {
                    pq.push(sum);
                }
                else    //since arrays are sorted in descending order,if A[i]+B[j]<=pq.top(), further elements in B won't yield a larger sum, so break the inner loop
                {
                    int curr_min=pq.top();
                    if(sum>curr_min)
                    {
                        pq.pop();
                        pq.push(sum);
                    }
                    else{
                        break;
                    }
                }
            }
        }
        
        while(!pq.empty())
        {
            result.push_back(pq.top());
            pq.pop();
        }
         reverse(result.begin(),result.end());
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends