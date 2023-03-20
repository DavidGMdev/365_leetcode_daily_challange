class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for ( int i = 0 ; i < flowerbed.size() && n ; i++ ){
            if ( !flowerbed[i] && ( !i || !flowerbed[i-1] ) && ( i == flowerbed.size()-1 || !flowerbed[i+1] )  ) {
                n--;
                flowerbed[i] = 1;
            }
        }
        return (!n);
    }
};
