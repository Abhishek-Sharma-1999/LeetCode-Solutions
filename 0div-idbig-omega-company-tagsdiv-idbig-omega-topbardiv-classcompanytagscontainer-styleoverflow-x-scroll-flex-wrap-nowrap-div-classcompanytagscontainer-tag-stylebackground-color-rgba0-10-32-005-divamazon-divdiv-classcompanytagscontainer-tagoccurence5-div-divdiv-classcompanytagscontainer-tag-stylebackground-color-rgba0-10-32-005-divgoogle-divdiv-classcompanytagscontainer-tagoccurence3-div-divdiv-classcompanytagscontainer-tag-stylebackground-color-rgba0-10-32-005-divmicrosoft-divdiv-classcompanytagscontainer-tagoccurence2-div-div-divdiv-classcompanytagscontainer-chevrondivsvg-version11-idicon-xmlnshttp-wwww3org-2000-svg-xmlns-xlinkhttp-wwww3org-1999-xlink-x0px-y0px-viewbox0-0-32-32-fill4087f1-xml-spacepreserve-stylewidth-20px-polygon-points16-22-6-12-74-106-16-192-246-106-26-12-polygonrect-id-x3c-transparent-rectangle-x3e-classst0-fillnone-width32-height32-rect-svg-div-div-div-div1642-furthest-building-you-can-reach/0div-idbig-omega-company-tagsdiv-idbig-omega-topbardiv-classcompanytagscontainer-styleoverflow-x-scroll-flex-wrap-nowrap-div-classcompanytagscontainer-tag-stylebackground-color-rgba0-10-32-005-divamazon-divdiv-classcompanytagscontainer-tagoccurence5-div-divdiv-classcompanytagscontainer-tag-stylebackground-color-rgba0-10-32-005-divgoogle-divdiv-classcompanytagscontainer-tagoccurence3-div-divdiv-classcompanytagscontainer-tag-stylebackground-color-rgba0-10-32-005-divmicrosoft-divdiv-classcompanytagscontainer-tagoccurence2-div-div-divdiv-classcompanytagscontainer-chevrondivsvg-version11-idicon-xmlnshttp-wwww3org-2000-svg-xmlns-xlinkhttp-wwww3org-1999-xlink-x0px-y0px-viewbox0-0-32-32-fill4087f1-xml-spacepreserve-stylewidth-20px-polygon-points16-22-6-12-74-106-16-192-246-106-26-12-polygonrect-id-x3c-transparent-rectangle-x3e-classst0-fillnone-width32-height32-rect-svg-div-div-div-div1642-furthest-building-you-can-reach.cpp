class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        priority_queue<int>pq;  //Max-Heap
        int i=0;
        for(;i<heights.size()-1;i++)
        {
            if(heights[i]>heights[i+1]){
                continue;
            }
            int diff=heights[i+1]-heights[i];
            if(diff<=bricks)
            {
                bricks=bricks-diff;
                pq.push(diff);  //i have to keep track of how, many bricks I have used in the past
            }
            else if(ladders>0){
                if(!pq.empty())
                {
                    int maxBricksUsedinPast=pq.top();
                    if(maxBricksUsedinPast>diff) //agar pehle past mein,jitni bricks use kari thi vo badi hai,differnce se, toh abhi unhe use karenge aur past mein ladders
                    {
                        bricks+=maxBricksUsedinPast;    //current bricks,mein unhe add kar diya
                        pq.pop();
                        bricks-=diff;   //ab current bricks,mein differnce ko subtract kar diya(no. of bricks used)
                        pq.push(diff); //aur iss differnce of bricks ko pq ein push kar diya
                    }
                }
                ladders--;  //either used in past or currently we are using
            }
         else{
            break;
        }
        }
         return i;

    }
};