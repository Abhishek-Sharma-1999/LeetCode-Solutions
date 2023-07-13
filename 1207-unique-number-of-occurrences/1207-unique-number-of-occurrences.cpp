class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Approach-1
            // int n=arr.size();
            // unordered_map<int,int>mp;
            // for(int i=0;i<n;i++)
            // {
            //     mp[arr[i]]++;
            // }
            // set<int>st;
            // for(auto i:mp)
            // {
            //     if(st.count(i.second)){
            //         return false;
            //     }
            //     st.insert(i.second);
            // }
            // return true;
        // Approach-2
        vector<int>vec(2001,0);
        for(int i:arr)
            vec[i+1000]++;
        sort(vec.begin(),vec.end());
        for(int i=1;i<2001;i++)
        {
            if(vec[i]!=0 && vec[i]==vec[i-1])
                return false;
        }
        return true;
    }
};