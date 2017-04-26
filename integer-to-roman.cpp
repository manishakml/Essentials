/* LC 12
 * Given an integer, convert it to a roman numeral.
 * Input is guaranteed to be within the range from 1 to 3999.
 */
#include<iostream>
#include<vector>
using namespace std;

vector<string> M = {"","M","MM","MMM"};
vector<string> C = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
vector<string> X = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
vector<string> I = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
string toRoman(int n) {
  if(n < 0) return ""; //handle negative
  if(n > 3999) return ""; //sanity check
  return M[n/1000] + C[(n%1000)/100] + X[(n%100)/10] + I[n%10];
}

/* Tested.
 * Time complexity: O(1)
 * Space complexity: O(1)
 */
