class Solution {
public:
    bool helper(int mid,vector<int>& weights,int days)
    {
        int count=1,sum=0;
        for(auto i:weights)
        {
            sum=sum+i;
            if(sum>mid)
            {
                count++;
                sum=i;
            }
        }
        if(count<=days)
            return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int maxCapacity=0,result,n=weights.size();
        for(int i=0;i<n;i++)
        {
            maxCapacity+=weights[i];
        }
        int low=*max_element(weights.begin(),weights.end());
        int high=maxCapacity;
        
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(helper(mid,weights,days))
            {
                result=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return result;
    }
};