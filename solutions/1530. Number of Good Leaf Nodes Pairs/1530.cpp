class Solution {
 public:
  int countPairs(TreeNode* root, int distance) {
    int ans = 0;

    dfs(root, distance, ans);

    return ans;
  }

 private:
  vector<int> dfs(TreeNode* root, int distance, int& ans) {
    vector<int> d(distance + 1);  // {distance: the number of leaf nodes}
    if (root == nullptr)
      return d;
    if (root->left == nullptr && root->right == nullptr) {
      d[0] = 1;
      return d;
    }

    const vector<int> dl = dfs(root->left, distance, ans);
    const vector<int> dr = dfs(root->right, distance, ans);

    for (int i = 0; i < distance; ++i)
      for (int j = 0; j < distance; ++j)
        if (i + j + 2 <= distance)
          ans += dl[i] * dr[j];

    for (int i = 0; i < distance; ++i)
      d[i + 1] = dl[i] + dr[i];

    return d;
  }
};
