class BSTIterator {
 public:
  BSTIterator(TreeNode* root, bool forward) : forward(forward) {
    while (root) {
      stack.push(root);
      root = forward ? root->left : root->right;
    }
  }

  int next() {
    TreeNode* node = stack.top(); stack.pop();

    const int res = node->val;
    node = forward ? node->right : node->left;
    while (node) {
      stack.push(node);
      node = forward ? node->left : node->right;
    }

    return res;
  }

 private:
  stack<TreeNode*> stack;
  bool forward;
};

class Solution {
 public:
  bool findTarget(TreeNode* root, int k) {
    if (!root) return false;

    BSTIterator left(root, true);
    BSTIterator right(root, false);

    for (int l = left.next(), r = right.next(); l < r;) {
      const int sum = l + r;
      if (sum == k) return true;
      if (sum < k)
        l = left.next();
      else
        r = right.next();
    }

    return false;
  }
};