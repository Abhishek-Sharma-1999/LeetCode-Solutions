class Solution {
public:
    int jump(vector<int>& nums) {
        int numberOfJumps=0;
        int CurrReach=0;
        int CurrMax=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(i+nums[i]>CurrMax)
            {
                CurrMax=i+nums[i];
            }
            if(i==CurrReach)
            {
                numberOfJumps++;
                CurrReach=CurrMax;
            }
        }
        return numberOfJumps;
    }
};