class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inToIndex;

    for (int i = 0; i < inorder.size(); ++i)
      inToIndex[inorder[i]] = i;

    return build(preorder, 0, preorder.size() - 1, inorder, 0,
                 inorder.size() - 1, inToIndex);
  }

 private:
  TreeNode* build(const vector<int>& preorder, int preStart, int preEnd,
                  const vector<int>& inorder, int inStart, int inEnd,
                  const unordered_map<int, int>& inToIndex) {
    if (preStart > preEnd)
      return nullptr;

    const int rootVal = preorder[preStart];
    const int rootInIndex = inToIndex.at(rootVal);
    const int leftSize = rootInIndex - inStart;

    TreeNode* root = new TreeNode(rootVal);
    root->left = build(preorder, preStart + 1, preStart + leftSize, inorder,
                       inStart, rootInIndex - 1, inToIndex);
    root->right = build(preorder, preStart + leftSize + 1, preEnd, inorder,
                        rootInIndex + 1, inEnd, inToIndex);
    return root;
  }
};
