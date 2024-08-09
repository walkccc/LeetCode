class Solution {
 public:
  Node* inorderSuccessor(Node* node) {
    // The successor is somewhere lower in the right subtree.
    if (node->right) {
      node = node->right;
      while (node->left)
        node = node->left;
      return node;
    }

    // The successor is somewhere upper in the tree.
    while (node->parent && node->parent->left != node)
      node = node->parent;
    return node->parent;
  }
};
