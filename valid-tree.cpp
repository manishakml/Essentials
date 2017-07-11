/* LC 261
 *  Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
 * For example:
 * Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
 * Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
 * Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges. 
 */
#include<iostream>
#include<unordered_set>
#include<vector>
#include<queue>
using namespace std;

bool validTree(int n, vector<pair<int, int>>& edges) {
        if(n <= 0) return false;
        vector<unordered_set<int>> m(n);
        
        for(pair<int,int> &p : edges) {
            m[p.first].emplace(p.second);
            m[p.second].emplace(p.first);
        }
        
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            int t = q.front();
            q.pop();
            n--;
            if(vis[t]){
                return false;
            }
            unordered_set<int> A = m[t];
            for(int i : A) {
                q.push(i);
                m[i].erase(t);    //remember to erase
            }
            vis[t] = true;
        }
        return n==0;
    }

/* Tested.
 * Note: 1)Set handles duplicate edges inherently (if (0,1) and (1,0) are given, when we try to insert the second one, it would not.
 * 2) We have to remove the vertex from the set in line 37, reason being, it will error out thinking there is a cycle when there is none. For eg., (0,1) has been inserted as (0,1) and (1,0). If we do not remove 0 from (1,0) set, it will think that 0,1 and 1,0 are 2 edges and hence cycle while in reality, it is only 1 edge.
 * 3) We need to add the edges in both directions because we do not know the order in which the edges are received. For instance, if 1,0; 2,0; 3,0; 4,1 are the 4 edges inserted only in one-way, since bfs begins with 0, it willprocess 0 without any further connections. 1,2,3,4 will not get processed and hence it will return false.
 * Time complexity: O(n)
 * Space complexity: O(2*E) where E is the number of edges.
 */
