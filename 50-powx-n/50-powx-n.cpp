class Solution{
public:
    double myPow(double x, long int n){  
        if(n < 0)
        {
            x = 1.0/x;
            n = -n;
        }
        
        double ans = 1.0;
        
        while(n)
        {
            if(n%2==1)
            {
                ans = ans * x;
                n--;
            }
            else
            {
                x = x * x;
                n = n / 2;
            }
        }
        return ans;
    }
};