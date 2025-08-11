struct T {
  int leftMax;
  int rightMax;
  int subtreeMax;
};

class Solution {
 public:
  int longestZigZag(TreeNode* root) {
    return dfs(root).subtreeMax;
  }

 private:
  T dfs(TreeNode* root) {
    if (root == nullptr)
      return {-1, -1, -1};
    const T left = dfs(root->left);
    const T right = dfs(root->right);
    const int leftZigZag = left.rightMax + 1;
    const int rightZigZag = right.leftMax + 1;
    const int subtreeMax =
        max({leftZigZag, rightZigZag, left.subtreeMax, right.subtreeMax});
    return {leftZigZag, rightZigZag, subtreeMax};
  }
};
