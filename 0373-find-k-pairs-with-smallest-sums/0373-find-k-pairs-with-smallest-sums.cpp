class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>> pq;   //Max-Heap
// max-heap islie liya kyunki, maximum sum ko upar rakhenge,agar koi sum usse chota aaya, toh us ko toh daal denge,lekin jo usse bda tha ,use nikaal denge        
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                int sum=nums1[i]+nums2[j];
// jab tak size less than k hain, tab tak hi insert karenge(kyunki hme sirf k hi elements chaiye)                
                if(pq.size()<k)
                {
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
//agar jo abhi sum nikala hai, vo chota aaya hai, max-heap ke top se,toh top ke element ko pop out kar denge,aur usse insert kar denge  
                else if(sum < pq.top().first)   
                {
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else    //for avoiding TLE
                {   
                    break;
                }
            }
        }
// in the end, sirf smaller sum vaale pair hi bachenge (toh unhe nikaalenge, phir vector mein store karva lenge)        
        while(!pq.empty())
        {
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};