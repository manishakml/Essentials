/* Find max number of collinear points */

int GCD(int a, int b) {
        if(!b) return a;
        else return GCD(b,a%b);
    }
    int maxPoints(vector<Point>& points) {
        int res = 0;        
        int n = points.size();
        if(n <= 1) return n;
        
        for(int i = 0; i < n; i++) {
            int same = 1;
            int vertical = 0;
            map<pair<int,int>, int> m;
            int count = 0;
            for(int j = i+1; j < n; j++) {
                if(points[i].x == points[j].x && points[i].y==points[j].y) {
                    same++;
                } else if(points[j].x == points[i].x) {
                    vertical++;
                } else {
                    int a = (points[j].x - points[i].x);
                    int b = (points[j].y - points[i].y);
                    int gcd = GCD(a,b);
                    a /= gcd;
                    b /= gcd;
                    m[make_pair(a,b)]++;
                    count = max(count,m[make_pair(a,b)]);
                }
                count = max(count,vertical);
            }
            
            res = max(res,count+same);
            
        }
        
        return res;
        
    }    
    
    /* Tested.
     * Time complexity: O(n^2)
     * Space complexity: O(n)
     */
