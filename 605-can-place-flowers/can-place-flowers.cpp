class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) {
            return true;
        }
        int i, size = flowerbed.size();
        for(i = 0; i < size; ++i) {
            if (flowerbed[i] == 1) {
                continue;
            } else if ( (i == 0 && size == 1) ||
            (i == 0 && i+1 < size && flowerbed[i+1] == 0) ||
            (i == size-1 && flowerbed[i-1] == 0) ||
            (i > 0 && flowerbed[i-1] == 0 && flowerbed[i+1] == 0) ) {
                flowerbed[i] = 1;
                --n;
            }
            if (n == 0) {
                return true;
            }
        }
        return false;
    }
};