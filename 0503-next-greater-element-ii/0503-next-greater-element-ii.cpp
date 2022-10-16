class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> res(n);
        for(int i=2*n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()<=nums[i%n])
            {
                st.pop();
            }
            if(st.empty())
            {
                res[i%n]=-1;
            }
            else
            {
                res[i%n]=st.top();
            }
            st.push(nums[i%n]);
        }
        return res;
    }
};