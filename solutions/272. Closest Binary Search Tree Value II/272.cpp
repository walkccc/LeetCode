class Solution {
 public:
  vector<int> closestKValues(TreeNode* root, double target, int k) {
    deque<int> dq;

    inorder(root, dq);

    while (dq.size() > k)
      if (abs(dq.front() - target) > abs(dq.back() - target))
        dq.pop_front();
      else
        dq.pop_back();

    return {dq.begin(), dq.end()};
  }

 private:
  void inorder(TreeNode* root, deque<int>& dq) {
    if (root == nullptr)
      return;

    inorder(root->left, dq);
    dq.push_back(root->val);
    inorder(root->right, dq);
  }
};
