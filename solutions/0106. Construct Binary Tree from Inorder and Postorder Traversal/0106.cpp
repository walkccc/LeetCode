class Solution {
 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> inorderToIndex;

    for (int i = 0; i < inorder.size(); ++i)
      inorderToIndex[inorder[i]] = i;

    return helper(inorder, 0, inorder.size() - 1,
                  postorder, 0, postorder.size() - 1,
                  inorderToIndex);
  }

 private:
  TreeNode* helper(const vector<int>& inorder, int iL, int iR,
                   const vector<int>& postorder, int pL, int pR,
                   const unordered_map<int, int>& inorderToIndex) {
    if (iL > iR)
      return nullptr;

    const int i = inorderToIndex.at(postorder[pR]);
    TreeNode* curr = new TreeNode(postorder[pR]);
    curr->left = helper(inorder, iL, i - 1, postorder, pL, pL + i - iL - 1,
                        inorderToIndex);
    curr->right = helper(inorder, i + 1, iR, postorder, pL + i - iL, pR - 1,
                         inorderToIndex);
    return curr;
  }
};
