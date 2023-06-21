class Solution {
public:
    typedef long long ll;
    ll findCost(vector<int>& nums, vector<int>& cost,ll mid)
    {
        ll res=0;
        for(int i=0;i<nums.size();i++)
        {
            res+=abs(mid-nums[i])*cost[i];
        }
        return res;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll answer=INT_MAX;
        ll left=*min_element(nums.begin(),nums.end());
        ll right=*max_element(nums.begin(),nums.end());
        while(left<=right)
        {
            ll mid=left+(right-left)/2;
//  finding cost ki agar (mid) ke equal sab elements ko karein,toh kitni cost hai           
            ll cost1=findCost(nums,cost,mid);   
            ll cost2=findCost(nums,cost,mid+1);
            answer=min(cost1,cost2);
            if(cost1<cost2) //cost2 bda aaya hai,toh cost1 ke left mein check karenge
            {
                right=mid-1;
            }
            else    //cost2 chotta aaya hai,toh right mein check karenge
            {
                left=mid+1;
            }
        }
//agar answer, INT_MAX hai,matlab saare elements equal hai,tab 0 return karenge
        return answer==INT_MAX ? 0 : answer;
    }
};