class BSTIterator {
 public:
  BSTIterator(TreeNode* root) {
    pushLeftsUntilNull(root);
  }

  bool hasNext() {
    return !nexts.empty();
  }

  int next() {
    auto [root, fromNext] = nexts.top();
    nexts.pop();
    if (fromNext)
      pushLeftsUntilNull(root->right);
    prevsAndCurr.push(root);
    return root->val;
  }

  bool hasPrev() {
    return prevsAndCurr.size() > 1;
  }

  int prev() {
    nexts.push({prevsAndCurr.top(), /*fromNext=*/false});
    prevsAndCurr.pop();
    return prevsAndCurr.top()->val;
  }

 private:
  stack<TreeNode*> prevsAndCurr;
  stack<pair<TreeNode*, /*fromNext=*/bool>> nexts;

  void pushLeftsUntilNull(TreeNode* root) {
    while (root != nullptr) {
      nexts.push({root, /*fromtNext=*/true});
      root = root->left;
    }
  }
};
