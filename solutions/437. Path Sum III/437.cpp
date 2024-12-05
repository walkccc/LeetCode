class Solution {
 public:
  int pathSum(TreeNode* root, int sum) {
    if (root == nullptr)
      return 0;
    return dfs(root, sum) +            //
           pathSum(root->left, sum) +  //
           pathSum(root->right, sum);
  }

 private:
  int dfs(TreeNode* root, int sum) {
    if (root == nullptr)
      return 0;
    return (sum == root->val) +                //
           dfs(root->left, sum - root->val) +  //
           dfs(root->right, sum - root->val);
  }
};
