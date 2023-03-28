class Solution {
public:
    int temp[366];  //no of days,365 tak jaayenge,isliye 366 liya hai
    // Recursion + Memoization
    int solve(vector<int>& days, vector<int>& costs,int &n,int index)
    {
        if(index>=n)
            return 0;
        
        if(temp[index]!=-1)
            return temp[index];
        // 1st day pass
        int cost_1=costs[0]+solve(days,costs,n,index+1);
        
        // 7 day pass
        int j=index;
        int max_day=days[index]+7;
        while(j<n && days[j]<max_day)   //j kashin,increment hota hua,n se aage na nikal jaaye
        {   
            j++;
        }
        int cost_7=costs[1]+solve(days,costs,n,j);
        
        // 15 day pass
        j=index;
        max_day=days[index]+30;
        while(j<n && days[j]<max_day)   //j kashin,increment hota hua,n se aage na nikal jaaye
        {   
            j++;
        }
        int cost_30=costs[2]+solve(days,costs,n,j);
        
        return temp[index]=min({cost_1,cost_7,cost_30});
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        memset(temp,-1,sizeof(temp));   //initializing every element of temp with -1
        return solve(days,costs,n,0);
    }
};