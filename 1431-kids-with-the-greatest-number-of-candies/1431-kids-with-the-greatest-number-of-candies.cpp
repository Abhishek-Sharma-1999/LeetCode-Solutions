class Solution {
public:
    int maxEle(vector<int> & candies)
    {
        int ans=INT_MIN;
        for(auto i:candies)
        {
            if(i>=ans)
                ans=i;
        }
        return ans;
    }
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        vector<bool> ans(n,false);
        int MAX=maxEle(candies);
        for(int i=0;i<n;i++)
        {
            if(candies[i]+extraCandies>=MAX)
                ans[i]=true;
        }
        return ans;
    }
};