/* public interface FirstCommonAncestor {

    /**
     * Given two nodes of a tree,
     * method should return the deepest common ancestor of those nodes.
     *
     *          A
     *         / \
     *        B   C
     *       / \
     *      D   E
     *         / \
     *        G   F
     *
     *  commonAncestor(D, F) = B
     *  commonAncestor(C, G) = A
     *  commonAncestor(E, B) = B
     
     Node commonAncestor(Node one, Node two);
  }
 
  class Node {

    final Node parent;
    final Node left;
    final Node right;


   public Node(Node parent, Node left, Node right) {
        this.parent = parent;
        this.left = left;
        this.right = right;
    }

    boolean isRoot() {
        return parent == null;
    }
}

Implement commonAncestor.
*/

#include<iostream>
#inlcude<cmath>
using namespace std;

int depth(Node *p) {
  int d = 0;
  while(p) {    //can also be while(!p.isRoot()) - it will count depth as one node lesser and that's ok since we only need the diff.
    d++;
    p = p->parent;
  }
  return d;
}

Node * commonAncestor(Node *p, Node *q) {
  int d1 = depth(p);
  int d2 = depth(q);
  int diff = d1-d2;
  
  //p always holds the deeper node
  if(diff < 0) {
      Node* t = p;
      p = q;
      q = t;
      diff = -diff;
  }
  
  while(diff) {
    p = p->parent;
    diff--;
  }
  while(p && q) {
    if(p == q) return p;
    p = p->parent;
    q = q->parent;
  }
  return NULL;
}


/* Not tested.
 * Note there is another space-intensive solution on gfg using a map.
 * Time complexity: O(log n) where n is the number of nodes or O(h) where h is the height of the tree.
 * Space complexity: O(1)
 */
