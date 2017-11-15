/* Given n, return its square root. */

#include<iostream>
#include<climits>
using namespace std;
double precision = 0.0000000001;

double my_sqrt(double n) {
//handle negatives
    if(n < 0) {
        return INT_MIN;
    }
    double l, r;
    //handle differently for numbers between 0 and 1 and >1
    if(n < 1) {
        l = n;
        r = 1.0;
    } else {
        l = 1.0;
        r = n;
    }

    while(l <= r) {
        double m = l + ((r-l)/2);
        //we need a precision so that we dont have infinite loops, so the error margin is defined by this constant. Lower the precision value, higher the accuracy
        if(m <= ((n+precision)/m) && m >= ((n-precision)/m)){
            return m;
        } else if (m < n/m) {
            l = m;
        } else {
            r = m;
        }
    }
    //can return any negative values, since our output is not going to return negatives. We are only interested in +ve root.
    return INT_MIN;
}

int main(){
    double n;
    cout << "N:";
    cin >> n;
    cout << endl << my_sqrt(n);
    return 1;
}

/* Not tested thoroughly.
 * Time complexity: O(log (n/precision)) - we are doing binary search on n*(1/precision) values.
 * Spcae complexity: O(1)
 */
