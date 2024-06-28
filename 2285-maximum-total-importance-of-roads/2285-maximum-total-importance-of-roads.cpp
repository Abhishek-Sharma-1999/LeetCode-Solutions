class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>degree(n,0);
        for(auto &vec:roads)//yhaan par degree nikal li
        {
            int a=vec[0];
            int b=vec[1];
            degree[a]++;
            degree[b]++;
        }
        //jis vertice ki degree,sabse zayada hogi, use maximum value denge, kyunki vo baar-baar add hoga, toh hmara sum bhi increase hoga
        sort(degree.begin(),degree.end());//yhaan par degree ko sort kar liya
        long long value=1;
        long long result=0;
        for(int i=0;i<n;i++)
        {
            result+=(value*degree[i]);
            value++;
        }
        return result;
    }
};