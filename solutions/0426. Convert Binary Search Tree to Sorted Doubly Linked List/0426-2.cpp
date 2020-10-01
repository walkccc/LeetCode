class Solution {
 public:
  Node* treeToDoublyList(Node* root) {
    // very similar to 94. Binary Tree Inorder Traversal
    if (!root) return nullptr;

    stack<Node*> stack;
    Node* first = nullptr;
    Node* prev = nullptr;

    while (root || !stack.empty()) {
      while (root) {
        stack.push(root);
        root = root->left;
      }
      root = stack.top(), stack.pop();
      if (!first) first = root;
      if (prev) {
        prev->right = root;
        root->left = prev;
      }
      prev = root;
      root = root->right;
    }

    prev->right = first;
    first->left = prev;

    return first;
  }
};