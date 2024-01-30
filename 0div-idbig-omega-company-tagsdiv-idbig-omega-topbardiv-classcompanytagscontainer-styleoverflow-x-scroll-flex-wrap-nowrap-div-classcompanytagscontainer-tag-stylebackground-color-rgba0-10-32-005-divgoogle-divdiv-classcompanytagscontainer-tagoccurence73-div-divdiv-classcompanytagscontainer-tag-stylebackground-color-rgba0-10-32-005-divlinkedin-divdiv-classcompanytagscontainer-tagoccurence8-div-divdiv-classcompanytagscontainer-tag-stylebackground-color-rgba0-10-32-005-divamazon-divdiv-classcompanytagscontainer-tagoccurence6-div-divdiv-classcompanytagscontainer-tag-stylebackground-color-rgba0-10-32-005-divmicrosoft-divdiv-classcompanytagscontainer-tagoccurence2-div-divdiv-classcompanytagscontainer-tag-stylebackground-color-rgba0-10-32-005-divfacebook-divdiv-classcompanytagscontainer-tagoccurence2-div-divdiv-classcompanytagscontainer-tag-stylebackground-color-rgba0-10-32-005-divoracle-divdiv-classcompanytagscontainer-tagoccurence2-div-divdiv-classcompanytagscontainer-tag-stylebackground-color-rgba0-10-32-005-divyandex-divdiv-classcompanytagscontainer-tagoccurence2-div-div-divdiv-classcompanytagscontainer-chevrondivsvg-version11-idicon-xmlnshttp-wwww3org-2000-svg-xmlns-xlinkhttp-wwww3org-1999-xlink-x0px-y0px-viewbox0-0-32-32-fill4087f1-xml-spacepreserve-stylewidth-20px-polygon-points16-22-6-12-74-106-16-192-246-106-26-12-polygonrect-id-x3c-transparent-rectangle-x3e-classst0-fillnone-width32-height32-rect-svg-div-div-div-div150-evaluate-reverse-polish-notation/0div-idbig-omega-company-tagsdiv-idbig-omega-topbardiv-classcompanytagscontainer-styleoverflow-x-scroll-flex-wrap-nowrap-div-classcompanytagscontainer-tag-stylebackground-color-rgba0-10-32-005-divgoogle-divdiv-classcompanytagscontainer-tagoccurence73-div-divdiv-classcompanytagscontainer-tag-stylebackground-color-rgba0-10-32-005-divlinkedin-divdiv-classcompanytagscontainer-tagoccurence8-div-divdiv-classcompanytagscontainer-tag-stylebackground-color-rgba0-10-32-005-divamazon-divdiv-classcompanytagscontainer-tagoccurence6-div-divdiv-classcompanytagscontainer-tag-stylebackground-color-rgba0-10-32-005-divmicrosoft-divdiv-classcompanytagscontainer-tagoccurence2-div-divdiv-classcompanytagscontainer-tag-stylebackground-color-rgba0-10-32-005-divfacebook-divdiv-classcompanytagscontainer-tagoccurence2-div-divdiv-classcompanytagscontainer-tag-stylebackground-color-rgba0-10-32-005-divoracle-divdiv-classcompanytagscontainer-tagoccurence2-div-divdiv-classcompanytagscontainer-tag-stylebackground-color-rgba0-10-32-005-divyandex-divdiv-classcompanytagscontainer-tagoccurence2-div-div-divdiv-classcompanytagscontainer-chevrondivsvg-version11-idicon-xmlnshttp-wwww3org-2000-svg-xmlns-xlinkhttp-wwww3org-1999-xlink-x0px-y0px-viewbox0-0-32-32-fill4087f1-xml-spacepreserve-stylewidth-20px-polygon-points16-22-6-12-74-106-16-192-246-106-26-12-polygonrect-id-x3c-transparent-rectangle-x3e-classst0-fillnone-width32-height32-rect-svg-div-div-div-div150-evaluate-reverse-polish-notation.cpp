class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
        for(string s:tokens)
        {
            if(s=="+" || s=="-" || s=="*" || s=="/")
            {
                long long op2=st.top();     st.pop();
                long long op1=st.top();     st.pop();
                if(s=="+")  st.push(op1+op2);
                if(s=="-")  st.push(op1-op2);
                if(s=="*")  st.push(op1*op2);
                if(s=="/")  st.push(op1/op2);
            }
            else st.push(stoi(s));
            cout<<st.top()<<"+++";
        }
        return st.top();
    }
};