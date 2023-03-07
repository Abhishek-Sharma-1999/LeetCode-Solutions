class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // Approach 1 - O(N)
        // set<int>st;
        // int ans;
        // for(auto i:arr)
        // {
        //     st.insert(i);
        // }
        // for(int i=1;i<=3000;i++)
        // {
        //     if(st.find(i)==st.end())
        //         k--;
        //     if(k==0){
        //         ans=i;
        //         break;
        //     }
        // }
        // return ans;
        
        // Approach-2       // O(Log N)
        int low=0,high=arr.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int missing_till_mid=arr[mid]-(mid+1);
            if(missing_till_mid<k)
                low=mid+1;
            else
                high=mid-1;
        }
        return low+k;
    }
};