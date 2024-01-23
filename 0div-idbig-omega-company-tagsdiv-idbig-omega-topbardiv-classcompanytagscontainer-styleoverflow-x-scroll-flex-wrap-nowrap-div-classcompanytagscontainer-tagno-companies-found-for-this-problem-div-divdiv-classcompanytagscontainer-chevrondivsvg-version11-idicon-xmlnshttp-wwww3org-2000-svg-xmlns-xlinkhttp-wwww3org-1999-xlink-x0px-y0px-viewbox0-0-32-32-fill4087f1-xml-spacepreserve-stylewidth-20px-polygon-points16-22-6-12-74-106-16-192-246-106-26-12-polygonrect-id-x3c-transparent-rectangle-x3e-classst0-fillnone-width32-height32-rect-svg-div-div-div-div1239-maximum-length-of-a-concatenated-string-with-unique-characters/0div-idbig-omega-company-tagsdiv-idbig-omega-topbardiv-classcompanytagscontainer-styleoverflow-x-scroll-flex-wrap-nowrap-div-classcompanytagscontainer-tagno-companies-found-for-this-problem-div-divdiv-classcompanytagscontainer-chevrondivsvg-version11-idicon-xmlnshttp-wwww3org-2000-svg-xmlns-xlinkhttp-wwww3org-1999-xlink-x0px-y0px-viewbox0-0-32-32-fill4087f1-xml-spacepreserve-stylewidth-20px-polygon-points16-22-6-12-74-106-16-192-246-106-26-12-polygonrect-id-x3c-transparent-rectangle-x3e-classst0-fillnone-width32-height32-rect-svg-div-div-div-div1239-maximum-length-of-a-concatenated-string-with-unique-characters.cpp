class Solution {
public:
    bool hasDuplicate(string s1,string s2)
    {
        vector<int>arr(26,0);
        for(char &ch:s1)
        {
            if(arr[ch-'a']>0)   //{"aa","bb","cd"} -> agar already pehle fill kar rakha,hai toh
                return true;
            arr[ch-'a']++;
        }
        for(char &ch:s2)
        {
            if(arr[ch-'a']>0)  
                return true;
        }
        return false;
    }
    int solve(int i,vector<string>& arr,string temp,int n)
    {
        if(i>=n){
            return temp.length();
        }
        cout<<temp<<"++"<<endl;
        int include=0;
        int exclude=0;
        if(hasDuplicate(arr[i],temp))
        {
            exclude=solve(i+1,arr,temp,n);
        }
        else    //doesn't contains duplicate, we can either include it or exclude it
        {
            exclude=solve(i+1,arr,temp,n);
            temp+=arr[i];
            include=solve(i+1,arr,temp,n);
        }
        return max(include,exclude);
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        string temp="";
        return solve(0,arr,temp,n);
    }
};