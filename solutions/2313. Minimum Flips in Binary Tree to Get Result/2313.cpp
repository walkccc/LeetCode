class Solution {
 public:
  int minimumFlips(TreeNode* root, bool result) {
    return dp(root, result);
  }

 private:
  struct PairHash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
      return std::hash<T1>{}(p.first) ^ std::hash<T2>{}(p.second);
    }
  };

  unordered_map<pair<TreeNode*, bool>, int, PairHash> memo;

  // Returns the minimum flips to make the subtree become the target.
  int dp(TreeNode* root, bool target) {
    const pair<TreeNode*, bool> key{root, target};
    if (const auto it = memo.find(key); it != memo.cend())
      return it->second;
    if (root->val == 0 || root->val == 1)  // the leaf
      return root->val == target ? 0 : 1;
    if (root->val == 5)  // NOT
      return dp(root->left == nullptr ? root->right : root->left, !target);

    vector<pair<int, int>> nextTargets;
    if (root->val == 2)  // OR
      nextTargets = target ? vector<pair<int, int>>{{0, 1}, {1, 0}, {1, 1}}
                           : vector<pair<int, int>>{{0, 0}};
    else if (root->val == 3)  // AND
      nextTargets = target ? vector<pair<int, int>>{{1, 1}}
                           : vector<pair<int, int>>{{0, 0}, {0, 1}, {1, 0}};
    else  // root.val == 4 (XOR)
      nextTargets = target ? vector<pair<int, int>>{{0, 1}, {1, 0}}
                           : vector<pair<int, int>>{{0, 0}, {1, 1}};

    int ans = INT_MAX;
    for (const auto& [leftTarget, rightTarget] : nextTargets)
      ans = min(ans, dp(root->left, leftTarget) + dp(root->right, rightTarget));
    return memo[key] = ans;
  }
};
