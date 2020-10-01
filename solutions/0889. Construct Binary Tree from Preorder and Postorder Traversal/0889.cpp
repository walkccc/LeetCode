class Solution {
 public:
  TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    return helper(0, 0, pre.size(), pre, post);
  }

 private:
  TreeNode* helper(int i, int j, int n, vector<int>& pre, vector<int>& post) {
    if (n == 0) return NULL;

    TreeNode* root = new TreeNode(pre[i]);
    if (n == 1) return root;

    int k = j;
    while (post[k] != pre[i + 1]) ++k;
    int l = k - j + 1;

    root->left = helper(i + 1, j, l, pre, post);
    root->right = helper(i + l + 1, j + l, n - l - 1, pre, post);

    return root;
  }
};