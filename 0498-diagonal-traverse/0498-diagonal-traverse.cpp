class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>res;
        map<int,vector<int>>mp;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                mp[i+j].push_back(mat[i][j]);
            }
        }
        
        for(auto i:mp)
        {
            if((i.first)%2==0)
                reverse(i.second.begin(),i.second.end());   //even length vaalo ko reverse karna padega
            for(auto k:i.second)
            {
                res.push_back(k);
            }
        }
        return res;
    }
};