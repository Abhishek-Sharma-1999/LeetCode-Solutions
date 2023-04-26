class Solution {
public:
    int sum=0;
    int countDigits(int n)  //isi function se number of digits bhi nikaal lenge aur sum bhi
    {
        int count=0; //count of digits
        sum=0;  //jab bhi ye function call hoga,toh sum=0 karenge,kyunki nya number aaya hai
        while(n!=0)
        {
            sum+=n%10;
            n=n/10;
            count++;
        }
        return count;
    }
    int addDigits(int num) {
        if(num==0)
            return 0;
        while(countDigits(num)>1)
        {
            num=sum;
        }
        return num;
    }
};