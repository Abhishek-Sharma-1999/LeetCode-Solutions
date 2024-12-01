class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<float>st;
        for(int i:arr){
            if(st.find(2*i)!=st.end() || i%2==0 && st.find(i/2)!=st.end())
                return true;
            st.insert(i);
        }
        return false;
    }
};