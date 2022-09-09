class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        long a=LONG_MIN;
        long b=LONG_MIN;
        long c=LONG_MIN;
        for(int i:nums)
        {
            if(i==a || i==b || i==c)
                continue;
            if(i>a)
            {
                c=b;
                b=a;
                a=i;
            }
            else if(i>b)
            {
                c=b;
                b=i;
            }
            else if(i>c)
            {
                c=i;
            }
        }
        
        if(c==LONG_MIN)
            return (int)a;
        
        return (int)c;
    }
};