class Solution {
 public:
  // Same as 160. Intersection of Two Linked Lists
  Node* lowestCommonAncestor(Node* p, Node* q) {
    Node* a = p;
    Node* b = q;

    while (a != b) {
      a = a == nullptr ? q : a->parent;
      b = b == nullptr ? p : b->parent;
    }

    return a;
  }
};
