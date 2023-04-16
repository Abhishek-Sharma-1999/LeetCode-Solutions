class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0;
        stack<int> st;
        int m=pushed.size(),n=popped.size();
        while(i<m && j<n)
        {
            st.push(pushed[i]); //pehle push karenge
// aur stack empty na ho aur uska top ka element equal ho, popped ke toh stack mein se pop karte rahenge
            while(!st.empty() && st.top()==popped[j] && j<n)
            {
                st.pop();
                j++;
            }
            i++;
        }
        if(st.size()==0)
            return true;
        return false;
        
    }
};