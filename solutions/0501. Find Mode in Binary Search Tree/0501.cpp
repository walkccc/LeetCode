class Solution {
 public:
  vector<int> findMode(TreeNode* root) {
    vector<int> ans;
    TreeNode* pred;
    int count = 0;
    int maxCount = 0;

    function<void(TreeNode*)> inorder = [&](TreeNode* root) {
      if (!root) return;

      inorder(root->left);

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
      inorder(root->right);
    };

    inorder(root);

    return ans;
  }
};