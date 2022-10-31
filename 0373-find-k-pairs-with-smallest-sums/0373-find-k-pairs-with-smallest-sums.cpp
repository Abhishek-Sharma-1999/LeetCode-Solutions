class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int,pair<int,int>>> pq;     //{sum,{nums1,nums2}}
        // Inserting Elements into Heap
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                int sum=nums1[i]+nums2[j];
                
                if(pq.size()<k) 
                {
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else if(pq.top().first>sum)
                {
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else
                    break;
            }
        }
        
        while(!pq.empty())
        {
            res.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};