class Solution {
    bool isPossible(vector<int>& time, long long totalTrips,long long givenTime)
    {
        long long ans=0;
        for(int i:time)
        {
            ans+=(givenTime/i);
        }
        return ans>=totalTrips;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left=1;
        long long right=(long long) *min_element(begin(time),end(time))*totalTrips;
        while(left<right)
        {
            long long mid_time=left+(right-left)/2;
            if(isPossible(time,totalTrips,mid_time))
            {
                right=mid_time;
            }
            else
            {
                left=mid_time+1;
            }
            
        }
        return left;
    }
};