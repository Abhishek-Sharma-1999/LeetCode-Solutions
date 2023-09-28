class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int low=0,high=n-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                ans[low]=nums[i];
                low++;
            }
            else
            {
                ans[high]=nums[i];
                high--;
            }
        }
        return ans;
    }
};