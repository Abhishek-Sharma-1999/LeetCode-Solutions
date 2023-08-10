class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // Approach-1
        for(int i:nums)
        {
            if(i==target)
                return true;
        }
        return false;
    }
};