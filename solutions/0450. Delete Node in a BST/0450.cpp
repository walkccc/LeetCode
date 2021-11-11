class Solution {
 public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root)
      return nullptr;
    if (root->val > key)
      root->left = deleteNode(root->left, key);
    else if (root->val < key)
      root->right = deleteNode(root->right, key);
    else {  // root->val == key
      if (!root->left)
        return root->right;
      if (!root->right)
        return root->left;

      TreeNode* cache = root;
      root = getMin(root->right);
      root->right = deleteMin(cache->right);
      root->left = cache->left;
      delete cache;
    }

    return root;
  }

 private:
  TreeNode* getMin(TreeNode* root) {
    if (!root->left)
      return root;
    return getMin(root->left);
  }

  TreeNode* deleteMin(TreeNode* root) {
    if (!root->left)
      return root->right;
    root->left = deleteMin(root->left);
    return root;
  }
};
