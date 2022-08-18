class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp; // for counting frequency of every element
        priority_queue<int> pq;
        int res=0,removed=0;
        
        for(auto x:arr)
        {
            mp[x]++;    
        }
        for(auto x:mp)
        {
            pq.push(x.second);
        }
        int n=arr.size()/2;
        while(removed<n)
        {
            removed+=pq.top();
            pq.pop();
            res++;
        }
        return res;
    }
};