class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // Linear Search
        int i=0;
        int n=arr.size();
        while(i<n-1 && arr[i]<arr[i+1])
        {
            i++;
        }
        return i;
    }
};