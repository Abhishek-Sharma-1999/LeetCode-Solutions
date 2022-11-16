/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low=1;
        int high=n;
        while(1)
        {
            int mid=low+(high-low)/2;
            int res=guess(mid); //ye in-built given hai, ye result laake dega {-1,0,1} ki jo number hmne socha hai vo chotta hai,equal hai, ya bda hai
            if(res==0)
                return mid;
            else if(res==1)
                low=mid+1;
            else
                high=mid-1;
        }
    }
};