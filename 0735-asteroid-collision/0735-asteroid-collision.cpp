class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i:asteroids)
        {
            while(!st.empty() && st.top()>0 && i<0) //stack ke top mein positive element ho aur i par negative element aaya ho, yhi case hain jismein collision hoga
            {
                int sum=i+st.top(); // dono ko add kar denge (postive + negative)
                if(sum<0)   // sum chota aaya, matlab negative element bda hai,stack mein se positive element ko pop out kar denge
                {
                    st.pop();
                }
                else if(sum>0)  // sum,positive hai,matlab postive collision,tohbreak kar jaayenge
                {
                    i=0;
                    break;
                }
                else// sum==0
                {   //agar sum 0 ho gya,matlab postive aur negative equal the,toh stack mein se nikal denge
                    st.pop();
                    i=0;
                }
            }
            if(i!=0)
            {
                st.push(i);
            }
        }
        
        int n=st.size();
        vector<int>res(n);
        int i=n-1;
        while(!st.empty())
        {
            res[i]=st.top();
            i--;
            st.pop();
        }
        return res;
    }
};