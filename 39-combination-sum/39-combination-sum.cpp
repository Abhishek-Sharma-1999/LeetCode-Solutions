class Solution {
public:
    void findComb(vector<int>& candidates, int target,vector<int>& currComb,vector<vector<int>>& ans,int index)
    {
        if(index==candidates.size())
        {
            if(target==0)
            {
                ans.push_back(currComb);
            }
            return;
        }
        
      if(candidates[index]<=target)
      {
          currComb.push_back(candidates[index]);
          findComb(candidates,target-candidates[index],currComb,ans,index);
          currComb.pop_back();
      }
        
        findComb(candidates,target,currComb,ans,index+1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currComb;
        vector<vector<int>> ans;
        findComb(candidates,target,currComb,ans,0);
        return ans;
    }
};