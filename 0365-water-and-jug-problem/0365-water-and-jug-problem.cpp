class Solution {
public:
    int gcd(int a,int b)
    {
        if(a==0)
            return b;
        if(b==0)
            return a;
        if(a==b)
            return a;
        if(a>b)
            return gcd(a-b,b);
        return gcd(a,b-a);
    }
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if(jug1Capacity+jug2Capacity < targetCapacity)
        {
            return false;
        }
        
        if(jug1Capacity==targetCapacity || jug1Capacity+jug2Capacity==targetCapacity ||jug2Capacity==targetCapacity)
        {
            return true;
        }
        
        int k=gcd(jug1Capacity,jug2Capacity);
        
        if(targetCapacity%k==0)
        {
            return true;
        }
        
        return false;
    }
};