class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.length();
        // int i=0,j=0;
        // int total_time=0;
        // while(i<n && j<n)
        // {
        //     int max_time=0,curr_time=0;
        //     while(j<n && colors[i]==colors[j])
        //     {
        //     max_time=max(max_time,neededTime[j]);
        //     curr_time+=neededTime[j];
        //     j++;
        //     }
        //     i=j;
        //     total_time+=(curr_time-max_time);
        // }
        
        int total_time=0;
        for(int i=1;i<n;i++)
        {
            if(colors[i]==colors[i-1])
            {
                total_time+=min(neededTime[i],neededTime[i-1]);
                neededTime[i]=max(neededTime[i],neededTime[i-1]);
            }
        }
        return total_time;
    }
};