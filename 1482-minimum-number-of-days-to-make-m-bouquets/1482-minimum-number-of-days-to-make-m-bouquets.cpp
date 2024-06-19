class Solution {
public:
    int canMakeBoquet(vector<int>& bloomDay, int mid, int k)
    {
        int bouquetCount=0;
        int adjacentBoquet=0;
        int n=bloomDay.size();
        for(int i=0;i<n;i++)
        {
            if(bloomDay[i]<=mid){
                adjacentBoquet++;
            }
            else
            {
                adjacentBoquet=0;
            }
            if(adjacentBoquet==k)
            {
                bouquetCount++;
                adjacentBoquet=0;
            }
        }
        return bouquetCount;
        
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans=-1;
        int startDay=0,endDay=*max_element(bloomDay.begin(),bloomDay.end());
        while(startDay<=endDay)
        {
            int midDay=startDay+(endDay-startDay)/2;
            if(canMakeBoquet(bloomDay,midDay,k)>=m)
            {
                ans=midDay;
                endDay=midDay-1;
            }
            else
            {
                startDay=midDay+1;
            }
        }
        return ans;
    }
};