class Solution {
 public:
  vector<int> findMode(TreeNode* root) {
    vector<int> ans;

    inorder(root, ans);

    return ans;
  }

 private:
  TreeNode* pred = nullptr;
  int count = 0;
  int maxCount = 0;

  void inorder(TreeNode* root, vector<int>& ans) {
    if (!root)
      return;

    inorder(root->left, ans);

    if (pred && pred->val == root->val)
      ++count;
    else
      count = 1;

    if (count > maxCount) {
      maxCount = count;
      ans = {root->val};
    } else if (count == maxCount) {
      ans.push_back(root->val);
    }

    pred = root;
    inorder(root->right, ans);
  }
};
