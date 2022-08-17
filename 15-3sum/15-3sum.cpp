class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++)
        {
            if(i==0 || i>0 && nums[i]!=nums[i-1])
            {
                int a=nums[i];
                int low=i+1;
                int high=n-1;
                while(low<high)
                {
                    int b=nums[low];
                    int c=nums[high];
                    
                    if(a+b+c==0)
                    {
                        vector<int> temp{a,b,c};
                        ans.push_back(temp);
                        
                        while(low<high && nums[low]==nums[low+1])
                            low++;
                        while(low<high && nums[high]==nums[high-1])
                            high--;
                        
                        low++;
                        high--;
                    }
                    else if(a+b+c<0)
                        low++;
                    else
                        high--;
                }
            }
        }
        return ans;
    }
};