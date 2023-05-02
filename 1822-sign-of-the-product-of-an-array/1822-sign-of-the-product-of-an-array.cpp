class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count=0;
        for(auto i:nums)
        {
            if(i<0)
                count++;
            if(i==0)    //in case 0 is there
                return 0;
        }
        if(count%2==0) //if negative number comes even times,then it becomes +ve
            return 1;
        return -1;  //otherwise negative
    }
};