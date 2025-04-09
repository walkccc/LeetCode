class Solution {
 public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> ans;
    unordered_map<TreeNode*, int> nodeToDist;  // {node: distance to target}

    getDists(root, target, nodeToDist);
    dfs(root, k, 0, nodeToDist, ans);
    return ans;
  }

 private:
  void getDists(TreeNode* root, TreeNode* target,
                unordered_map<TreeNode*, int>& nodeToDist) {
    if (root == nullptr)
      return;
    if (root == target) {
      nodeToDist[root] = 0;
      return;
    }

    getDists(root->left, target, nodeToDist);
    if (const auto it = nodeToDist.find(root->left); it != nodeToDist.cend()) {
      // The target is in the left subtree.
      nodeToDist[root] = it->second + 1;
      return;
    }

    getDists(root->right, target, nodeToDist);
    if (const auto it = nodeToDist.find(root->right); it != nodeToDist.cend())
      // The target is in the right subtree.
      nodeToDist[root] = it->second + 1;
  }

  void dfs(TreeNode* root, int k, int dist,
           unordered_map<TreeNode*, int>& nodeToDist, vector<int>& ans) {
    if (root == nullptr)
      return;
    if (const auto it = nodeToDist.find(root); it != nodeToDist.cend())
      dist = it->second;
    if (dist == k)
      ans.push_back(root->val);

    dfs(root->left, k, dist + 1, nodeToDist, ans);
    dfs(root->right, k, dist + 1, nodeToDist, ans);
  }
};
