class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n=nums.size();  //number of rows
        //yhaan hum number of columns nahin le sakte, vo kam zayada hain
        map<int,int>mp;
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                mp[nums[i][j]]++;
            }
        }
        
        for(auto i:mp)  //agar vo element sab mein present hua,toh uski frequency number of rows ke equal hohi (matlab agar 3 rows hai,aur teeno rows mein element present hai,toh uski frequency 3 hogi)
        {
            if(i.second==n)
                res.push_back(i.first);
        }
        return res;
    }
};