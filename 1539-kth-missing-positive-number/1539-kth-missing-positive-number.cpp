class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        set<int>st;
        int ans;
        for(auto i:arr)
        {
            st.insert(i);
        }
        for(int i=1;i<=3000;i++)
        {
            if(st.find(i)==st.end())
                k--;
            if(k==0){
                ans=i;
                break;
            }
        }
        return ans;
    }
};