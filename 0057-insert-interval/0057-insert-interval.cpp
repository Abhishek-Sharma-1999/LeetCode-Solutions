class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        vector<vector<int>>result;
        int n=intervals.size();
        while(i<n)
        {
            /*
                agar current element ka end time hi chota hai, newInterval ke start time se 
                [1,2] < [5,9], toh [1,2] ko normally insert kar denge aur aage bad jaayenge
            */
            if(intervals[i][1]<newInterval[0])  
                result.push_back(intervals[i]);
             /*
                agar current element ka starting time hi bda hai, newInterval ke end time se 
                [11,20] < [5,9], toh break kar jaayenge, ye baad mein aagyega
            */
            else if(intervals[i][0]>newInterval[1])
                break;
            /*
            agar else mein mein aa gaye,matlab overlap kar rha hai,current element ka ending time, bda hai, newInterval ke starting time se
            [1,3] > [2,5]   -> min(1,2) and max(2,5) => [1,5]
            */
            else
            {
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
            }
            i++;
        }
        result.push_back(newInterval);
        while(i<n)
        {
           result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};