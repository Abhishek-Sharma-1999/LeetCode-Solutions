class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int num=abs(nums[i]);
            int index=num-1;    //because , agar nums[i]=3, hua, aur n=3 hai,tab 3rd index par nahin jaa sakte, nums[i]-1 => 3-1 =2 index par jaa sakte hain
            if(nums[index]<0)   // vo already negative hai, matlab uss index par, isi value se pehle ja chuke hain, matlab ye value repeat ho rahi hai
                ans.push_back(num);
            else
                nums[index]*=-1;    //vo negative, mark nahin hai, matlab jo abhi value hai, uske index par jaayenge aur use negaive mark kar denge,taaki agar dobara, se value mil aur usi index par gaye, aur vo already negative hai, matlab ye value repeat ho rahi hai
        }
        return ans;
    }
};