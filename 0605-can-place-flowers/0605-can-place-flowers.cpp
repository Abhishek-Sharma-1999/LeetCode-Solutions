class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // first element ke piche aur last element ke baad, koi element nahin hai,toh vhaan 0 ko place kar denge
        flowerbed.push_back(0); // inserting 0 at end
        flowerbed.insert(flowerbed.begin(),0);  //insertingg at begin
        for(int i=1;i<flowerbed.size()-1;i++)
        {
            if(flowerbed[i-1]+flowerbed[i]+flowerbed[i+1]==0)
            {
                n--;
                i++; //jis jagah flower lga diya hai,uski agli position par nhain lga sakte toh i++ par denge, taaki vo second place baad se shuru ho
            }
        }
        return n<=0;
    }
};