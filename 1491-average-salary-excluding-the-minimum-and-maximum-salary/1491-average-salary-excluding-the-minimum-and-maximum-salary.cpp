class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        double n=salary.size(),count=0,sum=0;
        for(int i=1;i<n-1;i++)
        {
            sum=sum+salary[i];
            count++;
        }
        return (double)sum/count;
    }
};