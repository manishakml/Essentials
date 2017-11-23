/* Given an array and a number of columns, print the elements column wise. */

void columnify(vector<int> &A, int c){
    int n = A.size();
    if(!n || c < 1) return;
    int q = n/c;
    int r = n%c;
    //i iterates over the number of rows. If there is a remainder, there will be 1 extra row, hence q+1. Otherwise, q defines n_rows.
    for(int i = 0; i < (r > 0 ? q + 1 : q); ++i) {
        for(int j = i, startColIdx = 0; j < n;) {
        //startcolidx (significant meaning for j > 0) crawls the first row in same increments as the current j. At each print, we have to evaluate that we are printing an idx < than the next column's start idx since we are dealing only with the current column and not the next column.
            if (j >= (startColIdx + q + (r > 0 ? 1 : 0)) break;
            cout << A[j] << '\t';
            count++;
            j += q;
            startColIdx += q;
            if (r > 0) {
              ++j; // extra; remainder consideration
              ++startColIdx;
              --r; // reduce remainder
            }
        }
        cout << endl;
    }
}


/* Not tested thoroughly.
 * Time complexity: O(n) since we visit each element only once
 * Space complexity: O(1)
 */
