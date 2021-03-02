class Solution {
 public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    vector<int> ans;
    unordered_map<TreeNode*, int> nodeToDist;  // {node: distance to target}

    getDists(root, target, nodeToDist);
    dfs(root, K, 0, nodeToDist, ans);

    return ans;
  }

 private:
  void getDists(TreeNode* root, TreeNode* target,
                unordered_map<TreeNode*, int>& nodeToDist) {
    if (!root)
      return;
    if (root == target) {
      nodeToDist[root] = 0;
      return;
    }

    getDists(root->left, target, nodeToDist);
    if (nodeToDist.count(root->left)) {
      // the target is in the left subtree
      nodeToDist[root] = nodeToDist[root->left] + 1;
      return;
    }

    getDists(root->right, target, nodeToDist);
    if (nodeToDist.count(root->right))
      // the target is in the right subtree
      nodeToDist[root] = nodeToDist[root->right] + 1;
  }

  void dfs(TreeNode* root, int K, int dist,
           unordered_map<TreeNode*, int>& nodeToDist, vector<int>& ans) {
    if (!root)
      return;
    if (nodeToDist.count(root))
      dist = nodeToDist[root];
    if (dist == K)
      ans.push_back(root->val);

    dfs(root->left, K, dist + 1, nodeToDist, ans);
    dfs(root->right, K, dist + 1, nodeToDist, ans);
  }
};
