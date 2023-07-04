class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Approach-1
        // unordered_map<int,int>mp;
        // for(auto i:nums)
        // {
        //     mp[i]++;
        // }
        // int res;
        // for(auto i:mp)
        // {
        //     if(i.second==1)
        //         res=i.first;
        // }
        // return res;
        
        // Approach-2 (Bit Manipulation)
        int res=0;
        for(int i=0;i<32;i++)
        {
            int temp=(1<<i);
            int count_one=0;
            int count_zero=0;
            for(int &num:nums)
            {
                if((num & temp)==0)
                    count_zero++;
                else
                    count_one++;
            }
            if(count_one%3==1)
                res=(res|temp);
        }
        return res;
    }
};