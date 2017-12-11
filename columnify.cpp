/* Given an array and a number of columns, print the elements column wise. */

void columnify(vector<int> &A, int c){
    int n = A.size();
    if(!n || c < 1) return;
    int q = n/c;
    int rem = n%c;
    //i iterates over the number of rows. If there is a remainder, there will be 1 extra row, hence q+1. Otherwise, q defines n_rows.
    for(int i = 0; i < (rem > 0 ? q + 1 : q); ++i) {
        int r = rem;
        for(int j = i, startColIdx = 0; j < n;) {
        //startcolidx (significant meaning for j > 0) crawls the first row in same increments as the current j. At each print, we have to evaluate that we are printing an idx < than the next column's start idx since we are dealing only with the current column and not the next column.
        /*consider n = 7, c = 5
            
           | sc:0| sc:2| sc:5| sc:6| sc:7
        i:0| a   | c   | e   | f   | g
           | j:1 | j:3 | //j:5; j >= sc+q(+1). So, it won't print 'e'
        i:1| b   | d   |
        */  
            if (j >= (startColIdx + q + (r > 0 ? 1 : 0)) break;
            cout << A[j] << '\t';
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
