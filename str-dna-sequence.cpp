/* LC 187
 *  All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
 * Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
 * For example,
 * Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
 * Return:
 * ["AAAAACCCCC", "CCCCCAAAAA"].
 */

#include<iostream>
#include<string>
#include<map>
using namespace std;

vector<string> dna(string s){
  vector<string> res;
  int n = s.length();
  unordered_map<string,int> m;
  if(n < 11) return res;
  
  for(int i = 0; i < n-9; i++) {
    string sub = s.substr(i,10);
    if(m[sub] == 1) {
        res.push_back(sub);
    }
    m[sub]++;
  }
  return res;
}

/* Tested.
 * Time complexity: O(n) where n is the string length.
 * Space complexity: O(2^20). Since there are only 4 nucleotides, each can be represented in bits as 00, 01, 10, 11. Thus 10-char string can be repn as 20-bit string. So, the upper bound on the storage is less than an int = 2^20.
 */
