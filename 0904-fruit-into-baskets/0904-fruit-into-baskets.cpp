class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int n=fruits.size(),ans=0;
        int left=0;
        for(int right=0;right<n;right++)    
        {
            mp[fruits[right]]++;
            while(left<=right && mp.size()>2)
            {
                mp[fruits[left]]--;
// agar erase karne ke baad uski frequency 0 ho gayi,toh us element ko remove kar denge
                if(mp[fruits[left]]==0)
                {
                    mp.erase(fruits[left]);
                }
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};