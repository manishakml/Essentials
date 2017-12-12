/* LC 207
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 * Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
 * For example:
 * 2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
 * 2, [[1,0],[0,1]]
 * There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 * Note:
 * The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input prerequisites.
 * click to show more hints.
 * Hints:
 * This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
 * Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
 * Topological sort could also be done via BFS.
 */
 bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int count = 0;
        if(numCourses < 1) {
            return true;
        }
        if(numCourses == 1 || prerequisites.size() == 0) {
            return true;
        }
        
        //degree keeps track of indegree of each node. If 1 depends on 0 and 2, indegree of 1 is 2.
        vector<int> degree(numCourses,0);
        //children keeps track of what nodes need to be processed next
        unordered_map<int,vector<int>> children;
        for(int i = 0; i < prerequisites.size();i++) {
            degree[prerequisites[i].first]++;
            children[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        
        queue<int> q;
        for(int i = 0; i < degree.size(); i++) {
            //if indegree is 0, it is a start node. We have to process all start nodes first.
            if(degree[i] == 0){
                q.push(i);
                degree[i]--;
            }
        }
        //no vertex with indegree 0 = no course can be started because each has dependency = cyclic.
        if(q.empty()) {
            return false;
        }
        
        while(!q.empty()){
            int t = q.front();
            q.pop();
            count++;
            for(auto &a : children[t]) {
                //we have processed one of its incoming edges, i.e. t. Reducing this count will also ensure that we handle duplicates. Suppose a is encountered again as a child of some other node, we reduce its count. a can have its count as 0 only once and hence is processed in the queue only once.
                degree[a]--;
                //a is now independent
                if(degree[a] == 0) {
                    q.push(a);
                }
            }
            
        }
        //if any of the children did not reach indegree 0, count will be less than numCourses.
        return count == numCourses;
    }
    
    /* Tested.
     * Time complexity: O(n)
     * Space complexity: O(n). If queue should not be used, time complexity increases to O(n^2)
     */
