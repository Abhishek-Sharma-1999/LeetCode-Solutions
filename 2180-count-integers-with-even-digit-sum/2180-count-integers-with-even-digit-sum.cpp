class Solution {
public:
    bool check(int n)
    {
        int sum=0;
        while(n>0)
        {
            sum=sum+(n%10);
            n=n/10;
        }
        return sum%2==0;
    }
    int countEven(int num) {
     int count=0;
        for(int i=2;i<=num;i++)
        {
            if(check(i))
                count++;
        }
        return count;
    }
};