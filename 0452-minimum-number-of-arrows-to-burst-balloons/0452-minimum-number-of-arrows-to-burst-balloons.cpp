class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end());
        vector<int> prev=points[0];
        int count=1;    //prev ko burst karne ke liye ek toh lagega hi,ab hum first se loop ko traverse karenge
        for(int i=1;i<n;i++)
        {
            int CurrStart=points[i][0]; //Current Starting-Point
            int CurrEnd=points[i][1];   //Current Ending Point
            int PrevStart=prev[0];  //previous starting point
            int PrevEnd=prev[1];    //previous ending point
//agar current ka starting point,previous ke ending point se bda hai,matlab ye overlap nahin kar rahe toh ek arrow aur lag jayega aur ab current vaala previous ban jayega               
            if(CurrStart>PrevEnd)  //No Overlap 
            {
                count++;
                prev=points[i];
            }
            else    //overlap ho gaye
            {
                prev[0]=max(PrevStart,CurrStart);
                prev[1]=min(PrevEnd,CurrEnd);
            }
        }
        return count;
    }
};