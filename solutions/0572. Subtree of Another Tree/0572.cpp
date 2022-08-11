class Solution {
 public:
  bool isSubtree(TreeNode* s, TreeNode* t) {
    if (!s)
      return false;
    if (isSameTree(s, t))
      return true;
    return isSubtree(s->left, t) || isSubtree(s->right, t);
  }

 private:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p || !q)
      return p == q;
    return p->val == q->val &&
           isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
  }
};
