/* LC 244
 * This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?
 * Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.
 * For example,
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 * Given word1 = “coding”, word2 = “practice”, return 3.
 * Given word1 = "makes", word2 = "coding", return 1.
 * Note:
 * You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 */
 #include <iostream>
 #include <vector>
 #include <map>
 #include <cmath>
 #include <climits>
 using namespace std;
 
 class WordDistance {
    unordered_map<string, vector<int>> m;
    public:
    WordDistance(vector<string> &A) {
       int n = A.size();
       for(int i = 0; i < n; i++) {
          m[A[i]].push_back(i);
       }
    }
    
    int word_distance(string w1, string w2) {
       vector<int> A = m[w1];
       vector<int> B = m[w2];
       int i = 0, j = 0, minD = INT_MAX, m = A.size(), n = B.size();
       
       while(i < m && j < n) {
          minD = min(minD, abs(A[i],B[j]));
          if(A[i] < B[j]) {
             i++;
          } else {
             j++;
          }
       }
       return minD;
    }
 };
 
 /* Not tested.
  * Time complexity: O(n) where n is the number of words in the list.
  * Space complexity: O(n).
  */
 
