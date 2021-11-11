class Solution {
 public:
  vector<int> closestKValues(TreeNode* root, double target, int k) {
    deque<int> q;

    inorder(root, q);

    while (q.size() > k)
      if (abs(q.front() - target) > abs(q.back() - target))
        q.pop_front();
      else
        q.pop_back();

    return {begin(q), end(q)};
  }

 private:
  void inorder(TreeNode* root, deque<int>& q) {
    if (!root)
      return;

    inorder(root->left, q);
    q.push_back(root->val);
    inorder(root->right, q);
  }
};
