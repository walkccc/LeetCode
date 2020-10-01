class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inorderToIndex;

    for (int i = 0; i < inorder.size(); ++i)
      inorderToIndex[inorder[i]] = i;

    function<TreeNode*(int, int, int, int)> helper = [&](int pL, int pR, int iL,
                                                         int iR) -> TreeNode* {
      if (pL > pR) return nullptr;

      const int i = inorderToIndex[preorder[pL]];
      TreeNode* curr = new TreeNode(preorder[pL]);
      curr->left = helper(pL + 1, pL + i - iL, iL, i - 1);
      curr->right = helper(pL + i - iL + 1, pR, i + 1, iR);

      return curr;
    };

    return helper(0, preorder.size() - 1, 0, inorder.size() - 1);
  }
};