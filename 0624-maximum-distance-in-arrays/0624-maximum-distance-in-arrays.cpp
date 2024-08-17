class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int MAX=arrays[0].back();
        int MIN=arrays[0].front();
        int result=INT_MIN,n=arrays.size();
        for(int i=1;i<n;i++)
        {
            int currMax=arrays[i].back();
            int currMin=arrays[i].front();
            result=max({result,abs(currMin-MAX),abs(currMax-MIN)});
            MAX=max(MAX,currMax);
            MIN=min(MIN,currMin);
        }
        return result;
    }
};