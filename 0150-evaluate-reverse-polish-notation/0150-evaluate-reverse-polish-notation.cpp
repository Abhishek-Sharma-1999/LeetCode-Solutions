class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int>st;
        for(auto i:tokens)
        {
            if(i=="+" || i=="-" || i=="*" || i=="/")
            {
                long long int op2=st.top();   st.pop();
                long long int op1=st.top();   st.pop();
                
                if(i=="+")
                {
                    st.push(op1+op2);
                }
                if(i=="-")
                {
                    st.push(op1-op2);
                } 
                if(i=="*")
                {
                    st.push(op1*op2);
                } 
                if(i=="/")
                {
                    st.push(op1/op2);
                }
            }
            else
            {
                st.push(stoi(i));   //converts string to integer
            }
        }
        return st.top();
    }
};