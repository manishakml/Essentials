/* LC 605
 * Given a flowerbed represented as 1s and 0s, 1 indicates a planted flower and 0 indicates a free slot, and given a number k, is it possible to plant k flowers in the bed such that no 2 flowers are adjacent?
 */
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n <= 0) {
                return true;
        }
        int N = flowerbed.size();
        if(N < n) {
                return false;
        }

        for(int i = 0; i < N; i++){
                if(flowerbed[i] == 0 && ((i == 0 || flowerbed[i-1] == false) && (i == N-1 || flowerbed[i+1] == false))){
                        n--;
                        if(n == 0){
                            break;
                        }
                        i++;
                } else if(flowerbed[i] == 1){
                        i++;
                }
        }
        return n == 0;
    }
};

/* Tested.
 * Time complexity: O(n)
 * Space: O(1)
 */
