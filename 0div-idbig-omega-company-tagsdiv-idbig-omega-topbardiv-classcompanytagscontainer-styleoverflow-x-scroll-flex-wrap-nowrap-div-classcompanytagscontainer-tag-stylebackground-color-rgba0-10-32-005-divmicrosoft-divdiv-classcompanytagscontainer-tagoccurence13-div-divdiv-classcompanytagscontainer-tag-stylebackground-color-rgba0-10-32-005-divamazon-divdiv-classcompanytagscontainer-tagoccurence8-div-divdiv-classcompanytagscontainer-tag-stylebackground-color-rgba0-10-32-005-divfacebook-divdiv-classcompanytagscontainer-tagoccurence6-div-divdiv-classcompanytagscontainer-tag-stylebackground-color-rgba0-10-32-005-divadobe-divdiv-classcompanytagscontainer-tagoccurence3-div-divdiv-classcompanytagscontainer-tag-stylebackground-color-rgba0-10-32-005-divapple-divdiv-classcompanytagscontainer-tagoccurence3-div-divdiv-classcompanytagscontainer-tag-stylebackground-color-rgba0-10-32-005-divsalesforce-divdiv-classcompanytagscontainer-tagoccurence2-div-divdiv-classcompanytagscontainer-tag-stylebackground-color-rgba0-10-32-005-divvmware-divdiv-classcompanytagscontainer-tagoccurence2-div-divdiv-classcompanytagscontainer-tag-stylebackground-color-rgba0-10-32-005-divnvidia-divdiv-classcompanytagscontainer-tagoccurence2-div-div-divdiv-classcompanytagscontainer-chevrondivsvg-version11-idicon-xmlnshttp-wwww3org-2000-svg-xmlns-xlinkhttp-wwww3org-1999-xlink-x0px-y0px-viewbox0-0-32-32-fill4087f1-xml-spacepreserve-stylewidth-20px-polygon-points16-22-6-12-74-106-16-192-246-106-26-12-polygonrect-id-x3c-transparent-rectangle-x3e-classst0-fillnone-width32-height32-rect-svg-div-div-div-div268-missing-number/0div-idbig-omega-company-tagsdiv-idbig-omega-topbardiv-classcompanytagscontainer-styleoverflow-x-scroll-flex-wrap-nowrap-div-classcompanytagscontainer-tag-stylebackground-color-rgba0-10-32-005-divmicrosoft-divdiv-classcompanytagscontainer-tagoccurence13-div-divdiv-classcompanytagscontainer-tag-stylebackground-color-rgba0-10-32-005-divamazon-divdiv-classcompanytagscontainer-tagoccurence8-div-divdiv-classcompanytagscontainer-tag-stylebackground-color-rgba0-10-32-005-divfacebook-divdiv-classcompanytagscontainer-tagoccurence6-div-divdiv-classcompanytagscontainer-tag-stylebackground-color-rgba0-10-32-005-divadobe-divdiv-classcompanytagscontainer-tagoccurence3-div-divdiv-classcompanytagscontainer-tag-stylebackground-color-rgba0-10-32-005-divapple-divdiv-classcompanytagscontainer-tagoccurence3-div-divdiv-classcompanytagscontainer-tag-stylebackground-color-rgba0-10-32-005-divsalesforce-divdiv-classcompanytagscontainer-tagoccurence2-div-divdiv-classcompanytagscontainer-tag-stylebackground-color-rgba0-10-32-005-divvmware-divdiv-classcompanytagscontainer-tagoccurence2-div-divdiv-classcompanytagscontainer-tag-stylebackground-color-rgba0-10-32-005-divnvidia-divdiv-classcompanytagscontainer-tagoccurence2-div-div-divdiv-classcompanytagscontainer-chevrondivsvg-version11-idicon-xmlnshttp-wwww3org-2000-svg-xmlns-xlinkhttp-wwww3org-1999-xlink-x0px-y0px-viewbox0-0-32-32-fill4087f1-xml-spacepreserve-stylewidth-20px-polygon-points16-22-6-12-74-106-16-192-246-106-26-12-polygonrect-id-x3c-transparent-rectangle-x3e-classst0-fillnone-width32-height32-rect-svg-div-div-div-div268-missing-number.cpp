class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size(),res=0,sum=(n*(n+1)/2);
        for(int i=0;i<n;i++)
        {
            res=res+nums[i];
        }
        return sum-res;
    }
};