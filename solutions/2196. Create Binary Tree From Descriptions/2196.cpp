class Solution {
 public:
  TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    unordered_map<TreeNode*, TreeNode*> childToParent;
    unordered_map<int, TreeNode*> valToNode;

    for (const vector<int>& d : descriptions) {
      const int p = d[0];
      const int c = d[1];
      const bool isLeft = d[2];
      TreeNode* parent = valToNode.contains(p)
                             ? valToNode[p]
                             : (valToNode[p] = new TreeNode(p));
      TreeNode* child = valToNode.contains(c)
                            ? valToNode[c]
                            : (valToNode[c] = new TreeNode(c));
      childToParent[child] = parent;
      if (isLeft)
        parent->left = child;
      else
        parent->right = child;
    }

    // Pick a random node and traverse upwardly.
    TreeNode* root = childToParent.begin()->second;
    while (childToParent.contains(root))
      root = childToParent[root];
    return root;
  }
};
