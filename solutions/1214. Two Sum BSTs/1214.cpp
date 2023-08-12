class BSTIterator {
 public:
  BSTIterator(TreeNode* root, bool leftToRight) : leftToRight(leftToRight) {
    pushUntilNull(root);
  }

  bool hasNext() {
    return !stack.empty();
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
  bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
    BSTIterator bst1(root1, true);
    BSTIterator bst2(root2, false);

    for (int l = bst1.next(), r = bst2.next(); true;) {
      const int sum = l + r;
      if (sum == target)
        return true;
      if (sum < target) {
        if (!bst1.hasNext())
          return false;
        l = bst1.next();
      } else {
        if (!bst2.hasNext())
          return false;
        r = bst2.next();
      }
    }
  }
};
