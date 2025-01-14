class Solution {
 public:
  bool verifyPreorder(vector<int>& preorder) {
    int i = 0;
    dfs(preorder, i, INT_MIN, INT_MAX);
    return i == preorder.size();
  }

 private:
  void dfs(const vector<int>& preorder, int& i, int min, int max) {
    if (i == preorder.size())
      return;
    if (preorder[i] < min || preorder[i] > max)
      return;

    const int val = preorder[i++];
    dfs(preorder, i, min, val);
    dfs(preorder, i, val, max);
  }
};
