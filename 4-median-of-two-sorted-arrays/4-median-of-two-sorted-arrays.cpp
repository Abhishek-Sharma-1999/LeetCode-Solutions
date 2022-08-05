class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int len=m+n;
        int arr[len];
        
        for(int i=0;i<m;i++)
        {
            arr[i]=nums1[i];
        }
        
        for(int i=0;i<n;i++)
        {
            arr[m+i]=nums2[i];
        }
        sort(arr,arr+len);
        
        if(len%2==0)
        {
            double sum=arr[len/2]+arr[(len/2)-1];
            return sum/2;
        }
        return arr[len/2];
    }
};