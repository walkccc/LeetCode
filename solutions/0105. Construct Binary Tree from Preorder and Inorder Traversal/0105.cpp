class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inorderToIndex;

    for (int i = 0; i < inorder.size(); ++i)
      inorderToIndex[inorder[i]] = i;

    return helper(preorder, 0, preorder.size() - 1,
                  inorder, 0, inorder.size() - 1,
                  inorderToIndex);
  }

 private:
  TreeNode* helper(const vector<int>& preorder, int pL, int pR,
                   const vector<int>& inorder, int iL, int iR,
                   const unordered_map<int, int>& inorderToIndex) {
    if (pL > pR)
      return nullptr;

    const int i = inorderToIndex.at(preorder[pL]);
    TreeNode* curr = new TreeNode(preorder[pL]);
    curr->left = helper(preorder, pL + 1, pL + i - iL, inorder, iL, i - 1,
                        inorderToIndex);
    curr->right = helper(preorder, pL + i - iL + 1, pR, inorder, i + 1, iR,
                         inorderToIndex);
    return curr;
  }
};
