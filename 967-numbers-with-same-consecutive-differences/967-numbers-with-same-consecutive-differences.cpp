class Solution {
public:
    vector<int> ans;
    int count_digit(int n)
    {
        int count=0;
        while(n>0)
        {
            count++;
            n=n/10;
        }
        return count;
    }
    
    void find_num(int num,int n,int k)
    {
        if(count_digit(num)==n)
        {
            ans.push_back(num);
            return;
        }
        for(int i=0;i<=9;i++)
        {
            int ld=num%10;
            if(abs(ld-i)==k)
            {
                int number=num*10+i;
                find_num(number,n,k);
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++)
        {
            find_num(i,n,k);
        }
       
        return ans;
    }
};