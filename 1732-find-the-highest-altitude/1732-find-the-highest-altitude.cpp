class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest=0;
        int res=0;
        for(int i=0;i<gain.size();i++)
        {
            res=res+gain[i];
            highest=max(highest,res);
        }
        return highest;
    }
};