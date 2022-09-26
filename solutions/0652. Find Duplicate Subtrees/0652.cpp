class Solution {
 public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    vector<TreeNode*> ans;
    unordered_map<string, int> count;
    encode(root, count, ans);
    return ans;
  }

 private:
  string encode(TreeNode* root, unordered_map<string, int>& count,
                vector<TreeNode*>& ans) {
    if (!root)
      return "";

    const string encoded = to_string(root->val) + "#" +
                           encode(root->left, count, ans) + "#" +
                           encode(root->right, count, ans);
    if (++count[encoded] == 2)
      ans.push_back(root);
    return encoded;
  }
};
