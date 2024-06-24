class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        vector<bool>isFlipped(n,false);
        int flipCount=0,flips=0;
        for(int i=0;i<n;i++)
        {
            if(i>=k && isFlipped[i-k]==true)
                flipCount--;
            if(flipCount%2==nums[i])
            {
                if(i+k>n)
                    return -1;
                flipCount++;
                isFlipped[i]=true;
                flips++;
            }
        }
        return flips;
    }
};