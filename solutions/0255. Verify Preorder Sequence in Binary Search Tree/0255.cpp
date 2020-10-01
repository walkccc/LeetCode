class Solution {
 public:
  bool verifyPreorder(vector<int>& preorder) {
    int i = 0;

    function<void(int, int)> dfs = [&](int min, int max) {
      if (i >= preorder.size() || preorder[i] < min || preorder[i] > max)
        return;

      const int val = preorder[i++];
      dfs(min, val);
      dfs(val, max);
    };

    dfs(INT_MIN, INT_MAX);

    return i == preorder.size();
  }
};