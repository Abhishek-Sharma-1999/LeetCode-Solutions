class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low=0;
        int high=letters.size()-1;
        int pos=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(letters[mid]>target)
            {
                pos=mid;    //even after finding the first big character,there is a possibility that another character lies on the left half
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if(pos==-1)
            return letters[0];  //when no big character s found,we have to return the first character
        return letters[pos];
    }
};