class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;
        int maxprofit=0;
        for(int i=0;i<prices.size();i++)
        {
            mini=min(mini,prices[i]);
            int curr_profit=prices[i]-mini;
            maxprofit=max(maxprofit,curr_profit);
        }
        return maxprofit;
    }
};