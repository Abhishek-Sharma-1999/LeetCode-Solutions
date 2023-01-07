class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(auto i:tasks)   //Storing number and their frequency in map
        {
            mp[i]++;
        }
        int round=0;
        for(auto i:mp)
        {
            int count=i.second; //Frequency 
            // if any number has frequency i ,we can't take it in 2 or 3 form ,so we return -1
            if(count==1)
            {
                return -1;
            }
            if(count%3==0)  //3k form
            {
                round+=count/3;
            }
            else
            {
                round+=(count/3)+1;
            }
        }
        return round;
    }
};