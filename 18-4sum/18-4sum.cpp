class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       
        vector<vector<int>> ans;
        long long int n=nums.size();
        sort(nums.begin(),nums.end());
        for(long long int i=0;i<n-3;i++)
        {
            for(long long int j=i+1;j<n-2;j++)
            {
                 long long int x=(long long)target-((long long)nums[i]+(long long)nums[j]);
                long long int low=j+1,high=n-1;
                while(low<high)
                {
                    long long int y=(long long)nums[low]+(long long)nums[high];
                    if(y==x)
                    {
                        vector<int> temp={nums[i],nums[j],nums[low],nums[high]};
                        ans.push_back(temp);
                        
                        while(low<high && nums[low]==nums[low+1]) low++;
                        while(low<high && nums[high]==nums[high-1]) high--;
                        
                        low++;
                        high--;   
                    }
                    else if(y<x)
                        low++;
                    else
                        high--;
                }
                while(j<n-1 && nums[j]==nums[j+1]) j++;
                while(i<n-1 && nums[i]==nums[i+1]) i++;
            }
        }
        return ans;
    }
};