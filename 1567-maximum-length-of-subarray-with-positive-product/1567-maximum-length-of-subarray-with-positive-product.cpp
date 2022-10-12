class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int poslen=0; // Positive-Length
        int neglen=0; // Negative-Length
        int maxlen=0;
        for(auto i:nums)
        {
            if(i==0) // If we have encountered 0, Reset both the lengths
            {
                poslen=0;
                neglen=0;
            }
            
            else
            {
                if(i<0) //  If we have encountered negative number swap both the lengths
                {
                    swap(poslen,neglen);
                }
                if(i>0 || poslen>0)
                {
                    poslen++;
                }
                if(i<0 || neglen>0)
                {
                    neglen++;
                }
                maxlen=max(poslen,maxlen);
            }
        }
        
        return maxlen;
    }
};