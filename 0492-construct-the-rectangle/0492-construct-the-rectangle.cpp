class Solution {
public:
    vector<int> constructRectangle(int area) {
        int L=area;
        for(int i=1;i<=sqrt(area);i++)
        {
            if(area%i==0)
                L=area/i;
        }
        return {L,area/L};
    }
};