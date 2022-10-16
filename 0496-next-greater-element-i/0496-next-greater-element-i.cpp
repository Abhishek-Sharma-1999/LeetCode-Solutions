class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;
        vector<int> res;
        int n=nums2.size();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<nums2[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                mp[nums2[i]]=-1;
            }
            else
            {
                mp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);  //pushing element intothe stack
        }
        
        for(auto i:nums1)
        {
            res.push_back(mp[i]);
        }
        
        return res;
    }
};