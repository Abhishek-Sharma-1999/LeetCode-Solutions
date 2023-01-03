class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row=strs.size();    
        int col=strs[0].size();
        int count=0;
        for(int i=0;i<col;i++)
        {
            for(int j=0;j<row-1;j++)    //last vaala row toh, kisi ke saath compare hoga nahin,isliye sirf second second last row tak jaayenge,vahi last row se compare karega apne aap ko
            {
                if(strs[j][i]>strs[j+1][i])
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};