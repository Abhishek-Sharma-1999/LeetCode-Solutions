class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0])
        {
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),cmp);
        int ans=0,diff=INT_MIN,n=properties.size();
        for(int i=n-1;i>=0;i--)
        {
            if(properties[i][1]<diff)
                ans++;
            if(properties[i][1]>diff)
                diff=properties[i][1];
        }
        return ans;
    }
};