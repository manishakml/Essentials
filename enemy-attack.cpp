/* Given an n*m grid with numbers, each number representing a type of enemy, return the best attack order for a given type of enemy.
 * If we have a grid like the following:
 0 0 1 0
 1 2 1 1
 1 2 1 1
 * The enemy we seek is 1 for instance. The best attack order is 0x2, 1x0 insce it kills all enemies of type 1. 0x2 kills more enemies of the type than 1x0.
 */
 
#include<iostream> 
#include<vector> 
#include<algorithm> 
#include<climits> 
using namespace std; 
 
typedef struct cell { 
    int i; 
    int j; 
    int cnt; 
}Cell; 
 
void dfs(vector<vector<int> >& A, int i, int j, int& c, int n, int m, int type) { 
    if(i < 0 || i > n-1 || j < 0 || j > m-1 || A[i][j] == INT_MIN || A[i][j] != type) { 
        return; 
    } 
    A[i][j] = INT_MIN; 
    c++; 
 
    dfs(A,i+1,j,c,n,m,type); 
    dfs(A,i,j+1,c,n,m,type); 
    dfs(A,i-1,j,c,n,m,type); 
    dfs(A,i,j-1,c,n,m,type); 
}

vector<Cell> attack(vector<vector<int> >& A, int type) {
    vector<Cell> res;
    int n = A.size();
    if(!n) return res;
    int m = A[0].size();
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(A[i][j] == type) {
                int c = 0;
                dfs(A,i,j,c,n,m,type);
                Cell new_cell;
                new_cell.i = i;
                new_cell.j = j;
                new_cell.cnt = c;
                res.push_back(new_cell);
            }
        }
    }
    sort(res.begin(),res.end(),[](Cell i, Cell j){return i.cnt > j.cnt;});
    return res;
}

int main() {
    vector<vector<int> > A;
    int n,m,type;
    cout << "\nEnter n:";
    cin >> n;
    cout << "\nEnter m:";
    cin >> m;
    cout << "\nEnter n*m grid:\n";
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            cin >> A[i][j];
        }
    }
    cout << "\nEnter enemy type:";
    cin >> type;
    vector<Cell> res = attack(A,type);
    cout << "\nBest attack strategy is:";
    for(int i = 0; i < res.size(); i++) {
        cout << endl << res[i].i << " " << res[i].j << " " << res[i].cnt;
    }
    return 0;
}       

/* Not tested thoroughly.
 * Time complexity: O(nm) for processing, O(nmlognm) for sorting. Hence O(nmlognm).
 * Space complexity: O(nm)
 */
