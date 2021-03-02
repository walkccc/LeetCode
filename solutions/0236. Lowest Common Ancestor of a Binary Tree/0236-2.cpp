class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    queue<TreeNode*> q_{{root}};
    unordered_map<TreeNode*, TreeNode*> parent{{root, nullptr}};
    unordered_set<TreeNode*> ancestors;  // p's ancestors

    // iterate until we find both p and q
    while (!parent.count(p) || !parent.count(q)) {
      root = q_.front(), q_.pop();
      if (root->left) {
        parent[root->left] = root;
        q_.push(root->left);
      }
      if (root->right) {
        parent[root->right] = root;
        q_.push(root->right);
      }
    }

    // insert all of p ancestors
    while (p) {
      ancestors.insert(p);
      p = parent[p];  // p becomes nullptr in the end
    }

    // go up from q until meet any of p's ancestors
    while (!ancestors.count(q))
      q = parent[q];

    return q;
  }
};
