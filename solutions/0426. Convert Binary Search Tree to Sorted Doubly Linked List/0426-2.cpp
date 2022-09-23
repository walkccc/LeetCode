class Solution {
 public:
  // very similar to 94. Binary Tree Inorder Traversal
  Node* treeToDoublyList(Node* root) {
    if (!root)
      return nullptr;

    stack<Node*> stack;
    Node* first = nullptr;
    Node* pred = nullptr;

    while (root || !stack.empty()) {
      while (root) {
        stack.push(root);
        root = root->left;
      }
      root = stack.top(), stack.pop();
      if (!first)
        first = root;
      if (pred) {
        pred->right = root;
        root->left = pred;
      }
      pred = root;
      root = root->right;
    }

    pred->right = first;
    first->left = pred;
    return first;
  }
};
