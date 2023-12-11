class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i:arr)
        {
            mp[i]++;
        }
        for(int i:arr)
        {
            if(mp[i]>n/4)
            {
                return i;
            }
        }
        return -1;
    }
};