/* Given a pizza, what is the maximum slices you can get by making n straight cuts?
 * Ans: If we have to maximize the number of slices, each cut should intersect all the previous cuts uniquely, i.e each line should have a unique intersection point with all other lines.
 * 1. Consider the nth line, if you miss out on intersecting even with one line, you lose all the slices that could have come out of that intersection.
 * 2. Consider the nth line, if you intersect it non-uniquely with some other line, 3 lines share the point. The extra region that could've come out with these 3 lines as the boundary is lost.
 * By 1 & 2, we see that we need both conditions to be fulfilled while making the cuts.
 
 * Is there a recurrence relation that we can come up with? If Rn is the number of regions that exist, by drawing the new line fulfilling the above conditions, what is Rn+1?
 * Ans: Rn+1 = Rn + n + 1 or Rn = Rn-1 + n
 * Solving the recurrence, Rn = (Rn-2 + n-1) + n = ((Rn-3 + n-2) + n-1) + n ....= R0 + 1+2+...n-1+n = 1 + (1+...n) = 1 + (n(n+1))/2. We see that it does not depend on previous Rn anymore.
 * Hence, this problem reduces to finding the solution based on the formula = O(1).
 */
 
 int no_of_pieces(int n){
  return 1 + (n*(n+1)/2);
 }
 
 /* Not tested.
  * Time complexity: O(1)
  * Space complexity: O(1)
  */

/* If we are given n, write an algorithm to produce n lines based on the above conditions. */
class line {
 public:
 double m;
 double c;
 line(int m, int c){this.m = m; this.c = c;}
};

vector<line> draw(int n){
 vector<line> res;
 double m = 0, c = 0;
 for(int i = 0; i < n; i++){
  res[i].push_back(new line(m,c));
  //increase m and c by 1 (or any arbitrary amt) progressively to get unique lines that intersect all previous lines.
  m += 1;
  c += 1;
 }
 return res;
}

/* Not tested.
 * Time complexity: O(n)
 * Space complexity: O(1)
 */

/* If we are given n lines, write an algorithm to generate the (n+1)th line based on above conditions. */
line generate(vector<line> &A) {
 set<pair<double,double>> invalid;  // keeps track of non-unique intersections.
 int max_slope = INT_MIN;
 for(int i = 0; i < A.size(); i++) {
  max_slope = max(max_slope, A[i].m);
 }
 double slope = max_slope + 1;   // we could find min_slope and use min_slope-1 too. All we need is a unique slope.
 
 for(int i = 0; i < A.size()-1; i++){
  for(int j = i+1; j < A.size(); j++) {
   pair<double,double> intersect;
   intersect.first = (A[j].c-A[i].c)/(A[i].m-A[j].m);  //formula for intersection. y = m1x+c1; y = m2x+c2. Calc. x in terms of m and c.
   intersect.second  = A[i].m*intersect.first + A[i].c //y = mx+c; x has been calc above.
   s.insert(intersect); // don't use this intersection for the new line
  }
 }
 double intercept = *s.rbegin() + 1; //Use any increment here. We can even use min_element -1. Set orders in increasing order.
 return new line(slope,intercept);
}

/* Not tested.
 * Time complexity: O(n^2)
 * Space complexity: O(n) for the intersections.
 */


