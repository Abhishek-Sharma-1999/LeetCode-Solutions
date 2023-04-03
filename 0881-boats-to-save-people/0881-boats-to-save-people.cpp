class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int j=people.size()-1,boats=0,i=0;
        while(i<=j)
        {
            if(people[i]+people[j]<=limit)
            {
                boats++;
                i++;
                j--;
            }
            else   //yaani ki last vaala bda hai,toh use ek boat mein daalenge phir j ko subtract kar denge
            {
                j--;
                boats++;
            }
        }
        return boats;
    }
};