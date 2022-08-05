class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        // return nums[nums.size()-k];
        priority_queue<int>pq(nums.begin(),nums.end());
        int ans;
        while(k--)
        {
            ans=pq.top();
            pq.pop();
        }
        return ans;
    }
};