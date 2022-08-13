class Solution {
public:
    int CountNeg(vector<int>& v)
    {
        int low=0,high=v.size()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(v[mid]>=0)
                low=mid+1;
            else
                high=mid-1;
        }
        return v.size()-high-1;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            count+=CountNeg(grid[i]);
        }
        return count;
    }
};