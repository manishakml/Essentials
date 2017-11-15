/* Given n, return its square root OR LC 69 */

#include<iostream>
#include<climits>
using namespace std;
double precision = 0.0000000001;

//Approach 1 if doubles have to be handled
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

//Approach 2 if int only has to be handled
int mySqrt(int x) {
    int l, r;
    
    if(x< 2) return x;
    l = 1;
    r = x;
    

    while(l <= r) {
        int m = l + ((r-l)>>1);
        if (m > x/m ) {
            r = m-1;
        } else {
           if((m+1) > x/(m+1))
                return m; 
            l = m+1;
        }
    }
    return INT_MIN;
}

int main(){
    double n;
    cout << "N:";
    cin >> n;
    cout << endl << my_sqrt(n);
    return 1;
}

/* A-1 : Not tested thoroughly. A-2 : Tested.
 * Time complexity: O(log (n/precision)) - we are doing binary search on n*(1/precision) values.
 * Spcae complexity: O(1)
 */
