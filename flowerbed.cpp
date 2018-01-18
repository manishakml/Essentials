/* LC 605
 * Given a flowerbed represented as 1s and 0s, 1 indicates a planted flower and 0 indicates a free slot, and given a number k, is it possible to plant k flowers in the bed such that no 2 flowers are adjacent?
 */
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        //if there are no new flowers to be planted
        if(n <= 0) {
                return true;
        }
        int N = flowerbed.size();
        //if the number of slots is lesser than the given flowers. Note this should not be <=. Counter case: If n = 1 and N = 1 and A[0] = 0, it is true.
        if(N < n) {
                return false;
        }

        for(int i = 0; i < N; i++){
            //if free slot and its neighbor(s) are false, decrement count. If count is 0, break. Otherwise loop will keep running for negative vals of n and result in wrong answer.
                if(flowerbed[i] == 0 && ((i == 0 || flowerbed[i-1] == false) && (i == N-1 || flowerbed[i+1] == false))){
                        n--;
                        if(n == 0){
                            break;
                        }
                        //once planted, its negihbor is not free, so can move by 2. once here and once in the loop
                        i++;
                } else if(flowerbed[i] == 1){
                    //it's not free. next slot is not useful, so skip it.
                        i++;
                }
        }
        //only if the given flowers are exhausted, return true.
        return n == 0;
    }
};

/* Tested.
 * Time complexity: O(n)
 * Space: O(1)
 */
