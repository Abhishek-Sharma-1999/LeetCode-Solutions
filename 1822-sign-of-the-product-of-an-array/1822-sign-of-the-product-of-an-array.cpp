class Solution {
public:
    int arraySign(vector<int>& nums) {
        long long int ans=0;
        for(auto i:nums){
            if(i==0)
            {
                return 0;
            }
            else if(i<0)
            {
                ans++;
            }
        }
        if(ans%2==0)
            return 1;
        else
            return -1;
    }
};