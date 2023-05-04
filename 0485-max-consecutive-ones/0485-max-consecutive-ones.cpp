class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0,ans=0;
        for(int i:nums)
        {
            if(i==1)
            {
                count++;
            }
            else
            {
                count=0;
            }
            ans=max(count,ans);
        }
        return ans;
    }
};