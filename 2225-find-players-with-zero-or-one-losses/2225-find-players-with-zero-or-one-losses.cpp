class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp;
        for(int i=0;i<matches.size();i++)
        {
            mp[matches[i][1]]++; //counting all loosers
        }
        vector<int> loser,winner;
        for(int i=0;i<matches.size();i++)
        {
            if(mp[matches[i][1]]==1)
            {
                loser.push_back(matches[i][1]);
                mp[matches[i][1]]=3;    //updating their losses, so that they can't come again
            }
            if(mp.find(matches[i][0])==mp.end())
            {
                winner.push_back(matches[i][0]);
                mp[matches[i][0]]=3; // now,making them looser so that they don't come again
            }
        }
        sort(winner.begin(),winner.end());
        sort(loser.begin(),loser.end());
        return {winner,loser};
    }
};