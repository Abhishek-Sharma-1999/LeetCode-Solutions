class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total_gas=accumulate(gas.begin(),gas.end(),0);
        int total_cost=accumulate(cost.begin(),cost.end(),0);
//total gas hi hmare pass kam hai,hmari total cost se,toh kisi bhi index se start karein,vapas us par aa hi nahin paayenge        
        if(total_gas<total_cost)    
        {
            return -1;
        }
        int result_index=0;
        int total=0;
        for(int i=0;i<n;i++)
        {
            total=total+gas[i]-cost[i];
// agar total negative aaya hai,matlab ye index toh nahin hai,tab aage bad jaayenge aur result_index ko +1 kar denge,aur totalko dobara 0            
            if(total<0)
            {
                total=0;
                result_index=i+1;
            }
        }
        return result_index;
    }
};