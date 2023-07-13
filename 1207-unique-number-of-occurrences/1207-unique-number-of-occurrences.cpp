class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Approach-1
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        set<int>st;
        for(auto i:mp)
        {
            if(st.count(i.second)){
                return false;
            }
            st.insert(i.second);
        }
        return true;
    }
};