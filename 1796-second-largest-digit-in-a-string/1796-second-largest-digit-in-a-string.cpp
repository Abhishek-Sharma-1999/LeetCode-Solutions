class Solution {
public:
    int secondHighest(string s) {
        set<int>st;
        for(char i:s)
        {
            if(isdigit(i))
                st.insert(i-'0');
        }
        if(st.size()<2)
            return -1;
        auto it=st.rbegin();    //rbegin()- reverse begin()
        return *(++it); //last 2 element
    }
};