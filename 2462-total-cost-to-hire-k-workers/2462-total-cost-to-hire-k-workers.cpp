class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long n=costs.size();
        long long i=0,j=n-1;
        priority_queue<long long,vector<long long>,greater<long long>>pq1,pq2;    //Min-Heap
        long long ans=0,hired=0;
        while(hired<k)
        {
            while(pq1.size()<candidates && i<=j)
            {
                pq1.push(costs[i]);
                i++;
            }
            while(pq2.size()<candidates && j>=i)
            {
                pq2.push(costs[j]);
                j--;
            }
            int a=pq1.size() > 0 ? pq1.top() : INT_MAX;
            int b=pq2.size() > 0 ? pq2.top() :INT_MAX;
            if(a<=b){
                ans=ans+a;
                pq1.pop();
            }else{
                ans=ans+b;
                pq2.pop();
            }
            hired++;
        }
        return ans;
    }
};