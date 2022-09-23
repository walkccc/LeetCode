class Solution {
 public:
  vector<int> findMode(TreeNode* root) {
    vector<int> ans;
    int count = 0;
    int maxCount = 0;

    inorder(root, count, maxCount, ans);
    return ans;
  }

 private:
  TreeNode* pred = nullptr;

  void inorder(TreeNode* root, int& count, int& maxCount, vector<int>& ans) {
    if (!root)
      return;

    inorder(root->left, count, maxCount, ans);
    updateCount(root, count, maxCount, ans);
    inorder(root->right, count, maxCount, ans);
  }

  void updateCount(TreeNode* root, int& count, int& maxCount,
                   vector<int>& ans) {
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
  }
};
