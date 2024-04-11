class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        string res="";
        for(int i=0;i<n;i++){
            while(res.length()>0 && res.back()>num[i] && k>0){
                res.pop_back();
                k--;
            }
            /*
            agar length greater than zero, hai aur element zero nahin hai, tabhi insert
            kar lenge, to avoid leading zeroes
            */
            if(res.length()>0 || num[i]!='0'){
                res.push_back(num[i]);
            }
        }
        /* agar saare increasing orders,mein hue toh, last ke delete karenge,jaise
        let's suppose 1234, ab saare increasing order mein already aa rahe hain, toh last se            delete karenge
        */
        while(res.length()>0 && k>0){
            res.pop_back();
            k--;
        }
        if(res==""){
            return "0";
        }
        return res;
    }
};