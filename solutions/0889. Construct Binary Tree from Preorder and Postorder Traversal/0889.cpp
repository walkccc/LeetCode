class Solution {
 public:
  TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    return helper(pre, post, 0, 0, pre.size());
  }

 private:
  // construct tree by pre[i..i + n) and post[j..j + n)
  TreeNode* helper(const vector<int>& pre, const vector<int>& post, int i,
                   int j, int n) {
    if (n == 0)
      return nullptr;

    TreeNode* root = new TreeNode(pre[i]);
    if (n == 1)
      return root;

    int l = 1;  // length of left subtree
    while (pre[i + 1] != post[j + l - 1])
      ++l;

    root->left = helper(pre, post, i + 1, j, l);
    root->right = helper(pre, post, i + 1 + l, j + l, n - 1 - l);

    return root;
  }
};
