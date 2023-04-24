class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; //Priority queue
        for(auto i:stones)
        {
            pq.push(i);
        }
        while(pq.size()!=1)
        {
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            pq.push(a-b);
        }
        return pq.top();
    }
};