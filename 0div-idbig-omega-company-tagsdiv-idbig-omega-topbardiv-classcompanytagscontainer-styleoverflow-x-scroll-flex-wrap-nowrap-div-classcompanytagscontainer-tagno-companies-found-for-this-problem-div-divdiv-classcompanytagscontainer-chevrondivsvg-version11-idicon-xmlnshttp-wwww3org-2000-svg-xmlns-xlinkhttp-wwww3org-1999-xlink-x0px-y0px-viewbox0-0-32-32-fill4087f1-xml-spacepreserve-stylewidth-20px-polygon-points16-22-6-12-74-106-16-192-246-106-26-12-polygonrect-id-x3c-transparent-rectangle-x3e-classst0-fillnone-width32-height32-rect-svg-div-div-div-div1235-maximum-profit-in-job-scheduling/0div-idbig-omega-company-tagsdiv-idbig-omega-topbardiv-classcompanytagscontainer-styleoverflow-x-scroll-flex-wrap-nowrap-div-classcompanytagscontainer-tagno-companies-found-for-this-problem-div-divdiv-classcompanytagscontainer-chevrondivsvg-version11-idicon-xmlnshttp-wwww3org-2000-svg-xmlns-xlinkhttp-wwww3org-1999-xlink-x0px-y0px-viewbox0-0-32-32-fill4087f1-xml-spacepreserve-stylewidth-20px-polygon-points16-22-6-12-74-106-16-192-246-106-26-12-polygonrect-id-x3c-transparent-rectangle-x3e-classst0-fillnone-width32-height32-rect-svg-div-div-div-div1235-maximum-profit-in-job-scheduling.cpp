class Solution {
public:
      int dp[50001];
      int n;
    //find the first job jiska starting point >= currentJob ka end point
    int getNextIndex(vector<vector<int>>& array, int l, int currentJobEnd) {
        int r = n-1;
        int result = n+1;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(array[mid][0] >= currentJobEnd) { //we can take this task
                result = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return result;
    }
    
    int solve(vector<vector<int>>& array, int i) {
        if(i >= n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int next  = getNextIndex(array, i+1, array[i][1]);
        
        int taken = array[i][2] + solve(array, next);
        int notTaken = solve(array, i+1);
        
        return dp[i] = max(taken, notTaken);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        memset(dp, -1, sizeof(dp));
        vector<vector<int>> array(n, vector<int>(3, 0)); //{s, e, p}
        for(int i = 0; i<n; i++) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }
        //sort kardo according to sart time
        sort(begin(array), end(array));
        return solve(array, 0);
    }
};