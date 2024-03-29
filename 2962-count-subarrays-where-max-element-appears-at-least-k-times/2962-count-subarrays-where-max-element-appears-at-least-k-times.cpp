class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maximumElement=-1;
        int n=nums.size();
        for(int i:nums)
        {
            if(i>maximumElement)
                maximumElement=i;
        }
        int i=0,j=0,count=0;
        long long ans=0;
        while(j<n)
        {
            if(nums[j]==maximumElement)
                count++;
            /*
            agar k ke equal ho gya count , matlab utni baar maximumElement mil gya
            [1,3,2,3,3,2,2,1] max=3 , k=2
             i     j
             toh i se j, tak ek sub-array hai, jismein count k baar hai maximum element ka
             saath mein j ke baad jitna bhi element bache hain, agar hum unhe bhi consider karein, 
             toh unmein bhi maximum element k ya usse zayada baar hi hoga
             [1,3,2,3,3,2,2,1] => [1,3,2,3,3]       [1,3,2,3,3,2]   [1,3,2,3,3,2,2],
             toh inhe count karne ke liye karenge (n-j),
             phir, i ko increase karenge, agar i equal hua maximumElement ke toh count--
            */
            while(count>=k)
            {
                ans+=(n-j);
                
                if(nums[i]==maximumElement)
                    count--;
                i++;
            }
            j++;
        }
        return ans;
    }
                   
};