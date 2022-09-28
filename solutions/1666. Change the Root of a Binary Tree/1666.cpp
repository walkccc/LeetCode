class Solution {
 public:
  Node* flipBinaryTree(Node* root, Node* leaf) {
    return reroot(root, leaf, nullptr);
  }

 private:
  Node* reroot(Node* root, Node* node, Node* newParent) {
    Node* oldParent = node->parent;
    node->parent = newParent;

    // clean up the child if it's the new parent
    if (node->left == newParent)
      node->left = nullptr;
    if (node->right == newParent)
      node->right = nullptr;

    // we meet the original root, so we're done
    if (node == root)
      return node;

    if (node->left)
      node->right = node->left;
    node->left = reroot(root, oldParent, node);

    return node;
  }
};
