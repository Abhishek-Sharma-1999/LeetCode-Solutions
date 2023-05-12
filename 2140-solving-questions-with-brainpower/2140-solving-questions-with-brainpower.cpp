class Solution {
    long long n;
    long long solve(long long int i,vector<vector<int>>& questions,vector<long long> &ans){
        if(i>=n)
            return 0;
        if(ans[i]!=-1)
            return ans[i];
        long long taken=questions[i][0]+solve(i+questions[i][1]+1,questions,ans);
        long long not_taken=solve(i+1,questions,ans);
        return ans[i]=max(taken,not_taken);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();
        vector<long long>ans(n+1,-1);
        return solve(0,questions,ans);
    }
};