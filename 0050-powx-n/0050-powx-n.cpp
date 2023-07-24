class Solution {
public:
    double solve(double x,long n)
    {
        if(n==0){   //kis ki bhi power o hoti hai,toh 1 aata hai (2^0=1)
            return 1;
        }
        if(n<0){   // negative numbers ko 1 se divide karke likh sakte hain (2^-7)=(1/(2^7))
            return solve(1/x,-n);
        }
        if(n%2==0){ //agar number even hua toh, (2^8)=(4^4)==> (2*2,8/2)
            return solve(x*x,n/2);
        }
        else{ //agar number odd hua toh, (2^9)=2*(4^4)==> 2*(2*2,8/2)
            return x*solve(x*x,(n-1)/2);
        }
    }
    double myPow(double x, int n) {
        return solve(x,(long)n);
    }
};