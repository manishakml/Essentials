/**
 * Leetcode 293
 * You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip twoconsecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.
 * Write a function to compute all possible states of the string after one valid move.
 * For example, given s = "++++", after one move, it may become one of the following states:
 * [
 *   "--++",
 *   "+--+",
 *   "++--"
 *  ]
 * If there is no valid move, return an empty list [].
 */
 
 #include<iostream>
 #include<string>
 using namespace std;
 
 vector<string> generateAllPossibleSequences(String s) {
    vector<string> result;
    if(s.length() < 2) {
       result.push_back(s);
       return result;
    }
    for(int i = 0; i < s.length()-1; i++) {
       if(s.charAt(i) == '+' && s.charAt(i+1) == '+') {
          String s2 = "";
          String replace = "--";
          String s1 = s.substr(0,i);
          if(i < s.length()-2) {
             s2 = s.substr(i+2);
          }
          String res = s1+replace+s2;
          result.push_back(res);
        }
      }
      return result;
  }
  
  /**
   * Time complexity:  O(n) where n is the number of characters in the string.
   * Space complexity: O(n) where n is the number of characters in the string. Result vector is O(n*k) where k is the number of combinations.
   * Not tested.
   */
