class Solution {
public:
    int minOperations(string s) {
        int start_with_one=0;   //101010101010......................
        int start_with_zero=0;  //010101010101......................
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(i%2==0)  //even_index
            {
                if(s[i]=='0')
                {
                    start_with_one++;
                }
                else    //s[i]=='1' , eve_index par 1 hai, 
                {
                    start_with_zero++;
                }
            }
            else    //odd index
            {
                if(s[i]=='1')
                {
                    start_with_one++;
                }
                else
                {
                    start_with_zero++;
                }
            }
        }
        return min(start_with_zero,start_with_one);
       
    }
};