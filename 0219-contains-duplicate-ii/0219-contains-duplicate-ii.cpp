class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
     unordered_map<int,int>mp;  //{element - index}
        for(int i=0;i<nums.size();i++)
        {
            // mp.count() will tell whatever ith index that I want, have I seen it before?
            if(mp.count(nums[i]))
            {
                if(abs(i-mp[nums[i]])<=k)
                    return true;
            }
 // if I have not seen this number before, insert the number with its position in the map        // and if the number is already present in the map, then update the position of that number
            mp[nums[i]]=i;
        }
        return false;
    }
};