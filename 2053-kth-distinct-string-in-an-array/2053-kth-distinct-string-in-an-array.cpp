class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mp;
        for(string &i:arr)
            mp[i]++;    //Mapping string with it's count
        for(string &i:arr)  //Traversing string array to get kth distict string
        {
            if(mp[i]==1)    //if string count is 1, we have found 1 distict string,then are  doing k--
                k--;
            if(k==0)    // the moment k becomes 0,we will return that string
                return i;
        }
        return "";
    }
};