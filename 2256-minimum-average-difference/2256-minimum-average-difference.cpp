class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long total_sum=0,curr_sum=0;
        int n=nums.size();
        // Calculating array sum
        for(auto i:nums)
        {
            total_sum+=i;
        }
        int mini=INT_MAX,ans=-1; // ans will conatin index value
        for(int i=0;i<n;i++)
        {
            curr_sum+=nums[i];
            int avg1=curr_sum/(i+1);
            // for last index, because this will contain divided by zero condition(if this condition is not present, it will throw an error)
            if(i==n-1)
            {
                if(avg1<mini)
                    return n-1;
                else
                    break;
            }
            int avg2=(total_sum-curr_sum)/(n-1-i);
            if(abs(avg2-avg1)<mini)
            {
                mini=abs(avg2-avg1);
                ans=i;  //Index
            }
        }
        return ans;
    }
};