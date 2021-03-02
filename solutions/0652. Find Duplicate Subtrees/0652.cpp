class Solution {
 public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    vector<TreeNode*> ans;
    unordered_map<string, int> count;

    preorder(root, count, ans);

    return ans;
  }

 private:
  string preorder(TreeNode* root, unordered_map<string, int>& count,
                  vector<TreeNode*>& ans) {
    if (!root)
      return "#";

    const string& hashed = to_string(root->val) + "," +
                           preorder(root->left, count, ans) + "," +
                           preorder(root->right, count, ans);
    if (count[hashed] == 1)
      ans.push_back(root);
    ++count[hashed];

    return hashed;
  }
};
