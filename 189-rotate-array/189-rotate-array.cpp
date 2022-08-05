class Solution {
public:
    void Rotate(vector<int>& nums,int low,int high)
    {
        while(low<high)
        {
            swap(nums[low],nums[high]);
            low++;
            high--;
        }
        
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        Rotate(nums,0,n-k-1);
        Rotate(nums,n-k,n-1);
        Rotate(nums,0,n-1);
    }
};