class Solution {
 public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    vector<TreeNode*> ans;
    unordered_map<string, int> count;

    function<string(TreeNode*)> preorder = [&](TreeNode* root) -> string {
      if (!root) return "#";

      string hashed = to_string(root->val) + "," +
                      preorder(root->left) + "," +
                      preorder(root->right);
      if (count[hashed] == 1)
        ans.push_back(root);
      ++count[hashed];

      return hashed;
    };

    preorder(root);

    return ans;
  }
};