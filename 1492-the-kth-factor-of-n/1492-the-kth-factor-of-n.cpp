class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int>res;
        for(int i=1;i<=n;i++){
            if(n%i==0)
                res.push_back(i);
        }
        return k>res.size() ? -1 : res[k-1];
    }
};