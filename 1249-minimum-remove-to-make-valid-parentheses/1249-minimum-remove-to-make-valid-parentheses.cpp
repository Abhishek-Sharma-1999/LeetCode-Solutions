class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        stack<int>st;   //we will be storing indexes, instead of characters
        unordered_set<int>removeIndex;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(st.size()){
                    st.pop();
                }
                /*
                    agar stack mein size nahin hai,aur closing bracket aa gya, matlab
                    ise remove karna hai, currently iska index store kra lenge
                    aur baad mein, jab string traverse karenge, toh is index ko vapas string mein                     daalenge hi nahin
                */
                else{   
                    removeIndex.insert(i);
                }
            }
        }
        /* 
        ab aisa bhi ho sakta hai sirf opening brackets aaye ho s="a(((((",
        toh ye toh removeIndex mein honge nahin hai, toh yhaan par stack ko check
        karenge, agar ek bhi element hua, toh use removeIndex mein daal denge
        */
        while(!st.empty()){
            removeIndex.insert(st.top());
            st.pop();
        }
        string result="";
        /*
        ab string ko traverse karenge, agar unhi index ko nayi result string mein daalenge
        jo removeIndex mein present nahin hai
        */
        for(int i=0;i<n;i++){
            if(removeIndex.find(i)==removeIndex.end()) //ye removeIndex mein nahin hai toh ise insert kar denge
            {
                result+=s[i];
            }
        }
        return result;
        
    }
};