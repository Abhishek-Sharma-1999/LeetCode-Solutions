class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string res="";
        for(int i=0;i<path.size();i++)
        {
            if(path[i]=='/')    //single-slash hai,toh continue kar denge
                continue;
            string temp;    //string to store part of string other than '/'
            while(i<path.size() && path[i]!='/')
            {
                temp+=path[i];
                i++;
            }
            if(temp==".") // single dot hai,toh aage continue kar denge
                continue;
            else if(temp=="..") //double dot,ek parent folder upar jaayenge,toh jo bhi stack mein hai,use pop kar denge
            {
                if(!st.empty()) //agar stack mein kuch hoga tabhi pop karenge
                    st.pop();
            }
            else //jo kuch bhi aayega use stack mein daal denge characters vgrah,folders ke naam
                st.push(temp);
        }
        while(st.size()!=0)
        {
            res="/"+st.top()+res;   //taaki hme string reverse na karni pade
            st.pop();
        }
        //agar string mein kuch aaya hi nahin,stack empty tha,toh question ke constraint ke according
        if(res.size()==0)
            return "/";
        return res;
        
    }
};