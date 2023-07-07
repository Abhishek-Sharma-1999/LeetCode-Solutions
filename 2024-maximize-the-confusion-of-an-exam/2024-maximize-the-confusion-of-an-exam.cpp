class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {    //sliding-window
        int i=0,j=0,res=0;
        int n=answerKey.size();
        int count_of_true=0;
        while(i<n)  //first pass (true->false) , pehle true ko false karenge
        {
            if(answerKey[i]=='T')
                count_of_true++;
//jaise hi true ki value k se zayada hogi,tabhi j ko aage bdayenge aur tab tak increase karenge,jab tak true nahin milta jaise hi milega, tab true ko subtract kar denge (uska count k se chota hona chaiye)            
            while(count_of_true>k)  
            {
                if(answerKey[j]=='T')
                    count_of_true--;
                j++;
            }
            res=max(res,i-j+1); //sath mein result ko store krate hue chalenge
            i++;
        }
        int count_of_false=0;
        i=0,j=0;    //ye first pass mein increase ho gaye honge,isliye inhe dobara re-initialise karenge
        while(i<n)  //second pass (false->true)
        {
            if(answerKey[i]=='F')
                count_of_false++;
            while(count_of_false>k)
            {
                if(answerKey[j]=='F')
                    count_of_false--;
                j++;
            }
            res=max(res,i-j+1);
            i++;

        }
        return res;
    }
};