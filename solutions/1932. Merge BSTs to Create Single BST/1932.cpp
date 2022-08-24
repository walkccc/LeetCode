class Solution {
 public:
  TreeNode* canMerge(vector<TreeNode*>& trees) {
    unordered_map<int, TreeNode*> valToNode;  // {val: node}
    unordered_map<int, int> count;            // {val: freq}

    for (const auto& tree : trees) {
      valToNode[tree->val] = tree;
      ++count[tree->val];
      if (tree->left)
        ++count[tree->left->val];
      if (tree->right)
        ++count[tree->right->val];
    }

    for (const auto& tree : trees)
      if (count[tree->val] == 1) {
        if (isValidBST(tree, nullptr, nullptr, valToNode) &&
            valToNode.size() <= 1)
          return tree;
        return nullptr;
      }

    return nullptr;
  }

 private:
  bool isValidBST(TreeNode* tree, TreeNode* minNode, TreeNode* maxNode,
                  unordered_map<int, TreeNode*>& valToNode) {
    if (!tree)
      return true;
    if (minNode && tree->val <= minNode->val)
      return false;
    if (maxNode && tree->val >= maxNode->val)
      return false;
    if (!tree->left && !tree->right && valToNode.count(tree->val)) {
      const int val = tree->val;
      tree->left = valToNode[val]->left;
      tree->right = valToNode[val]->right;
      valToNode.erase(val);
    }

    return isValidBST(tree->left, minNode, tree, valToNode) &&
           isValidBST(tree->right, tree, maxNode, valToNode);
  }
};
