class Solution {
 public:
  TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    unordered_map<int, int> postToIndex;

    for (int i = 0; i < post.size(); ++i)
      postToIndex[post[i]] = i;

    return build(pre, 0, pre.size() - 1, post, 0, post.size() - 1, postToIndex);
  }

 private:
  TreeNode* build(const vector<int>& pre, int preStart, int preEnd,
                  const vector<int>& post, int postStart, int postEnd,
                  const unordered_map<int, int>& postToIndex) {
    if (preStart > preEnd)
      return nullptr;
    if (preStart == preEnd)
      return new TreeNode(pre[preStart]);

    const int rootVal = pre[preStart];
    const int leftRootVal = pre[preStart + 1];
    const int leftRootPostIndex = postToIndex.at(leftRootVal);
    const int leftSize = leftRootPostIndex - postStart + 1;

    TreeNode* root = new TreeNode(rootVal);
    root->left = build(pre, preStart + 1, preStart + leftSize, post, postStart,
                       leftRootPostIndex, postToIndex);
    root->right = build(pre, preStart + leftSize + 1, preEnd, post,
                        leftRootPostIndex + 1, postEnd - 1, postToIndex);
    return root;
  }
};
