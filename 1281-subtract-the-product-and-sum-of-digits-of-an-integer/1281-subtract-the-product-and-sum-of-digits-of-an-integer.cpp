class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod=1,sum=0,rem,ans;
        while(n)
        {
            rem=n%10;
            prod*=rem;
            sum+=rem;
            n=n/10;
        }
        return prod-sum;
    }
};