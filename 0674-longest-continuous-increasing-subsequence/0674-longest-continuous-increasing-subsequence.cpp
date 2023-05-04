class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()<=1)  //Edge Case- [1], []
            return nums.size();
        int count=1,ans=0; //starting mein jo element milega, uska count toh leke chalenge hi
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1]){
                count++;
            }
            else
                count=1;
            ans=max(ans,count);

        }
        return ans;
    }
};