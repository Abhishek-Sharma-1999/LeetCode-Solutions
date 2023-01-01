class Solution {
    vector<vector<int>> subsets;    //it will contain all the subsets
public:
    void help(vector<int>& subset,int index,int k, int n)
    {
        if(n<0 || subset.size()>k)
        {
            return;
        }
        if(n==0 && subset.size()==k)
        {
            subsets.push_back(subset);
            return;
        }
        for(int i=index;i<=9;i++)
        {
            subset.push_back(i);
            help(subset,i+1,k,n-i);
            subset.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subset; //for current subset
        help(subset,1,k,n);
        return subsets;
    }
};