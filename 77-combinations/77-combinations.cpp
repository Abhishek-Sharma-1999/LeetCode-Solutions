class Solution {
public:
    vector<vector<int>> ans;
    void combinations(int index,int k,vector<int>& current,int n)
    {
        if(current.size()==k)
        {
            ans.push_back(current);
            return;
        }
        for(int i=index;i<=n;i++)
        {
            current.push_back(i);
            combinations(i+1,k,current,n);
            current.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> current;
        combinations(1,k,current,n);
        return ans;
    }
};