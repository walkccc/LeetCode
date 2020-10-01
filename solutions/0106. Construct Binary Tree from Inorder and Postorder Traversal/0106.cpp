class Solution {
 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> inorderToIndex;

    for (int i = 0; i < inorder.size(); ++i)
      inorderToIndex[inorder[i]] = i;

    function<TreeNode*(int, int, int, int)> helper = [&](int iL, int iR, int pL,
                                                         int pR) -> TreeNode* {
      if (iL > iR) return nullptr;

      const int i = inorderToIndex[postorder[pR]];
      TreeNode* curr = new TreeNode(postorder[pR]);
      curr->left = helper(iL, i - 1, pL, pL + i - iL - 1);
      curr->right = helper(i + 1, iR, pL + i - iL, pR - 1);

      return curr;
    };

    return helper(0, inorder.size() - 1, 0, postorder.size() - 1);
  }
};