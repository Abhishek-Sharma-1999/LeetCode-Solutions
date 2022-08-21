class Solution {
public:
    vector<int> CurrComb;
    vector<vector<int>> ans;
    void helper(int index,vector<int>& candidates, int target)
    {
        if(target == 0){
            ans.push_back(CurrComb);
            return; 
        }
        
        for(int i=index; i<candidates.size(); i++){
            if(i>index && candidates[i]==candidates[i-1]) 
                continue;
            if(candidates[i] > target) 
                break;
            
            CurrComb.push_back(candidates[i]);
            helper(i+1,candidates,target-candidates[i]);
            CurrComb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        // vector<int> temp;
        // vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        helper(0,candidates, target);
        return ans;
    }
    
};
