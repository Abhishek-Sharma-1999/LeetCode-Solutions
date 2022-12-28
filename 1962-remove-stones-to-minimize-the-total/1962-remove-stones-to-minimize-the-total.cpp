class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        int sum=0;
        for(int i=0;i<piles.size();i++)
        {
            pq.push(piles[i]);
            sum=sum+piles[i];
        }
        for(int i=1;i<=k;i++)
        {
            int max_ele=pq.top();
            pq.pop();
            int remove=max_ele/2;
            max_ele=max_ele-remove;
            sum=sum-remove;
            pq.push(max_ele);
        }
        return sum;
    }
};