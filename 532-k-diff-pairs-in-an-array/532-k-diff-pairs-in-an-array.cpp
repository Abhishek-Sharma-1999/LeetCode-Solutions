class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
// Map Solution T.C: O(n)  S.C.: O(n)
//         unordered_map<int,int> mp;
//         for(auto i:nums)
//         {
//             mp[i]++;
//         }
//         int ans=0;
        
//         for(auto x:mp)
//         {
//             if(k==0)
//             {
//                 if(x.second>1)
//                     ans++;
//             }
//             else if(mp.find(x.first+k)!=mp.end())
//                 ans++;
//         }
        
//         return ans;
        
        sort(nums.begin(),nums.end());
        int slow=0,fast=1;
        int ans=0;
        while(slow<nums.size() && fast<nums.size())
        {
            if(nums[fast]-nums[slow]==k)
            {
                ans++;
                slow++;
                fast++;
                while(fast<nums.size() && nums[fast]==nums[fast-1])
                {
                    fast++;
                }
                
            }
            
            else if(nums[fast]-nums[slow] > k)
            {
                slow++;
                if(fast-slow==0) // agar dono same position par aa gate, toh fast ko aage incerement kar denge
                    fast++;
            }
            
            else
                fast++;          
        }
        return ans;
    }
};