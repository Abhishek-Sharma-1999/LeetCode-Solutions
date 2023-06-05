class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int cz=coordinates.size();
        if(cz==1)
            return false;   //only one point
        if(cz==2)
            return true;   // 2 point,always a straight line
        int x0=coordinates[0][0],y0=coordinates[0][1];
        int x1=coordinates[1][0],y1=coordinates[1][1];
        int d_x=x1-x0,d_y=y1-y0;    // 0 and 1 are covered
        for(int i=2;i<cz;i++)
        {
            int x=coordinates[i][0];
            int y=coordinates[i][1];
            if(d_x*(y-y0)!=d_y*(x-x0))   // Two point formula of line, if (x2-x1)*(y1-y0) = (x1-x0)(y2-y1), then a straight line, otherwise not
            {
                return false;
            }
        }
        return true;
    }
};