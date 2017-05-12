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

//Approach 2: Extensible to any substr length, not just 10
vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        int n = 10;
        if(s.length() < 11) return res;
        //since there are only 4 chars, map them to bits
        unordered_map<char,int> map= { {'A',0}, {'C',1}, {'G',2}, {'T',3}};
        const string t = "ACGT";
        // if n is 10, each substr is 2*10 bits. So, there are 2^20 such substr possible.
        int m = 1 << (n*2);
        //We are following incremental approach. Suppose s = actgactg and n = 3. After processing 'act', we remove a and process g, thereby not recomputing ct. When we right shift, we get ---actg. We should remove a. So, we use mask on rhs of c.
        int mask = m-1;
        //A represents the substr is seen for the first time, B for second time onwards.
        vector<bool> A(m,false);
        vector<bool> B(m,false);
        int val = 0;
        //calc the first substr, i.e get it in bits format into val. Eg. above, get 'act'
        for(int i = 0; i < n; i++) {
            val = (val << 2) | map[s[i]];
        }
        A[val] = true;
        
        //start incremental processing
        for(int i = n; i < s.length(); i++) {
            val = ((val << 2) & mask) | map[s[i]];
          
            //if alphabetical order is needed, you can omit this step since we are not immediately populating result array.
            if(B[val]) continue;
          
            if(A[val]) {
                
              //if alphabetical order is not required, push it into result immediately; otherwise omit this step.
              res.push_back(s.substr(i-9,10));
                
              B[val] = true;
            } else{
                A[val] = true;
            }
        }
        //if alphabetical ordering of result is required, use this. Note that B array already has it in alphabetical order. We only have to convert the bits into char.
        /*for(int i = 0; i < m; i++) {
           if(B[i]) {
                int k = i;
                string str(n,'0');
                for(int j = 0; j < n; j++) {
                    str[n-1-j] = t[k&3];
                    k  >>= 2;
                }
                res.push_back(str);
           }
        }*/
        return res;

/* Tested.
 * Time complexity: O(n) where n is the string length.
 * Space complexity: O(2^20). Since there are only 4 nucleotides, each can be represented in bits as 00, 01, 10, 11. Thus 10-char string can be repn as 20-bit string. So, the upper bound on the storage is less than an int = 2^20.
 */
