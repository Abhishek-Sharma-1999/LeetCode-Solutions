class Solution {
public:
    
    int result = INT_MAX;
    int n;
    
    void solve(int index, vector<int>& cookies, vector<int>& children, int k) {
        if(index == cookies.size()) {
            
            int ans = *max_element(begin(children), end(children));
            result = min(result, ans);
            return;
        }
        
        int candy = cookies[index];
        for(int i = 0; i<k; i++) {
            children[i] += candy;   //Take
            solve(index+1, cookies, children, k);
            children[i] -= candy;   //Back-track
        }
        
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        vector<int> children(k);
        solve(0, cookies, children, k);
        
        return result;
    }
};