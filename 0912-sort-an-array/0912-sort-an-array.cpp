class Solution {
public:
    void merge(vector<int>& nums,int low,int mid,int high)
    {
        if(low>=high)
            return;
        vector<int> temp(high-low+1);
        int i=low,j=mid+1,k=0;
        while(i<=mid && j<=high)
        {
            if(nums[i]<=nums[j])
            {
                temp[k++]=nums[i++];
            }
            else
            {
                temp[k++]=nums[j++];    
            }
        }
        
        while(i<=mid)
        {
            temp[k++]=nums[i++];
        }
        
        while(j<=high)
        {
            temp[k++]=nums[j++];
        }
        // copying the elements back into orignal array
        for(int i=0;i<k;i++)
        {
            nums[low+i]=temp[i];
        }
    }
    void mergeSort(int low,int high,vector<int>& nums)
    {
        if(low<high)
        {
            int mid=low+(high-low)/2;
            mergeSort(low,mid,nums);
            mergeSort(mid+1,high,nums);
            merge(nums,low,mid,high);
        }
            
       
    }
    vector<int> sortArray(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        mergeSort(low,high,nums);
        return nums;
    }
};