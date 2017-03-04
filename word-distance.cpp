/* LC 243
 * Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
 * For example,
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 * Given word1 = “coding”, word2 = “practice”, return 3.
 * Given word1 = "makes", word2 = "coding", return 1.
 * Note:
 * You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 */
 
 #include<iostream>
 #include<cmath>
 #include<climits>
 #include<vector>
 using namespace std;
 
 int word_distance(vector<string> &words, string w1, string w2) {
    int idx1 = -1, idx2 = -1;
    int minD = INT_MAX;
    int n = words.size();
    for(int i = 0; i < n; i++) {
       if(words[i] == w1) idx1 = i;
       if(words[i] == w2) idx2 = i;
       if(idx1 != -1 && idx2 != -1) {
          minD = min(minD, abs(idx1-idx2));
       }
    }
    return minD;
 }
 
 /* Tested.
  * Time complexity: O(n) where n is the number of words in the list.
  * Space complexity: O(1).
  */
