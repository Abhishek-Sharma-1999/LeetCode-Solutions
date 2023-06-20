class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0)
            return nums;
       
        vector<int>res(n,-1);
        
        if(n< 2*k+1)    //toh na hum,left ja paayenge na right
            return res;
        
        vector<long long int>prefix_sum(n,0);
        prefix_sum[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix_sum[i]=nums[i]+prefix_sum[i-1];
        }
        for(int i=k;i<=n-k-1;i++)
        {
            int left_index=i-k;
            int right_index=i+k;
            long long int sum=prefix_sum[right_index];
            if(left_index>0)
            {
                sum-=prefix_sum[left_index-1];
            }
            res[i]=sum/(2*k+1);
        }
        return res;
    }
};