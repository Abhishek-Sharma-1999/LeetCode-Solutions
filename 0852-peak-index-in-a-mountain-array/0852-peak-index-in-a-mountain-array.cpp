class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // Linear Search
        // int i=0;
        // int n=arr.size();
        // while(i<n-1 && arr[i]<arr[i+1])
        // {
        //     i++;
        // }
        // return i;
        
        //Binary Search
        int low=0,high=arr.size()-1,ans=0;
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(arr[mid]<arr[mid+1])
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        return high;    //end or low (both will give same result)
    }
};