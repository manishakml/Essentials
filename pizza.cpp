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
