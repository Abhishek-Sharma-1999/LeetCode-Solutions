class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        for(int i:bills){
            if(i==5)
                five++;
            else if(i==10){
                if(five>0){
                    five--;
                    ten++;
                }
                else
                    return false;
            }
            else if(five>0 && ten>0){   //i==20
                five--;
                ten--;
            }
            else if(five>=3) //20 ko 3 five bhi de sakte hain
                five-=3;
            else    //i=20 hai, na hmare pass five>=3 hai, na ten>0 hai, toh false;
                return false;
        }
        return true;
    }
};