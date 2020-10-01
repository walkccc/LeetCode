class Solution {
 public:
  int countPairs(TreeNode* root, int distance) {
    int ans = 0;

    function<vector<int>(TreeNode*)> dfs = [&](TreeNode* root) {
      vector<int> d(distance + 1);  // {distance: # of leaf nodes}
      if (!root) return d;
      if (!root->left && !root->right) {
        d[0] = 1;
        return d;
      }

      vector<int> dl = dfs(root->left);
      vector<int> dr = dfs(root->right);

      for (int i = 0; i < distance; ++i)
        for (int j = 0; j < distance; ++j)
          if (i + j + 2 <= distance)
            ans += dl[i] * dr[j];

      for (int i = 0; i < distance; ++i)
        d[i + 1] = dl[i] + dr[i];

      return d;
    };

    dfs(root);

    return ans;
  }
};
