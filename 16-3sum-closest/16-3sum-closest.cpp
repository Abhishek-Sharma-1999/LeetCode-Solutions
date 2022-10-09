class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff=INT_MAX;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            int a=nums[i];
            int low=i+1;
            int high=n-1;
            while(low<high)
            {
                int b=nums[low];
                int c=nums[high];
                
                if(a+b+c==target)
                {
                    return target;
                }
                
                else if(abs(a+b+c-target)<diff)
                {
                    diff=abs(a+b+c-target);
                    ans=a+b+c;
                }
                if(a+b+c<target)
                {
                    low++;
                }
                else
                {
                    high--;
                }
            }
        }
        return ans;
    }
};