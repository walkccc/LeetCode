class BSTIterator {
 public:
  BSTIterator(TreeNode* root, bool leftToRight) : leftToRight(leftToRight) {
    pushUntilNull(root);
  }

  int next() {
    TreeNode* root = stack.top();
    stack.pop();
    pushUntilNull(leftToRight ? root->right : root->left);
    return root->val;
  }

 private:
  stack<TreeNode*> stack;
  bool leftToRight;

  void pushUntilNull(TreeNode* root) {
    while (root != nullptr) {
      stack.push(root);
      root = leftToRight ? root->left : root->right;
    }
  }
};

class Solution {
 public:
  bool findTarget(TreeNode* root, int k) {
    if (root == nullptr)
      return false;

    BSTIterator left(root, true);
    BSTIterator right(root, false);

    for (int l = left.next(), r = right.next(); l < r;) {
      const int sum = l + r;
      if (sum == k)
        return true;
      if (sum < k)
        l = left.next();
      else
        r = right.next();
    }

    return false;
  }
};
