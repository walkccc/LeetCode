class Solution {
 public:
  int findClosestLeaf(TreeNode* root, int k) {
    int ans = -1;
    int minDist = 1000;
    // {node: distance to TreeNode(k)}
    unordered_map<TreeNode*, int> nodeToDist;

    getDists(root, k, nodeToDist);
    getClosestLeaf(root, 0, nodeToDist, minDist, ans);

    return ans;
  }

 private:
  void getDists(TreeNode* root, int k,
                unordered_map<TreeNode*, int>& nodeToDist) {
    if (!root)
      return;
    if (root->val == k) {
      nodeToDist[root] = 0;
      return;
    }

    getDists(root->left, k, nodeToDist);
    if (nodeToDist.count(root->left)) {
      // the TreeNode(k) is in the left subtree
      nodeToDist[root] = nodeToDist[root->left] + 1;
      return;
    }

    getDists(root->right, k, nodeToDist);
    if (nodeToDist.count(root->right))
      // the TreeNode(k) is in the right subtree
      nodeToDist[root] = nodeToDist[root->right] + 1;
  }

  void getClosestLeaf(TreeNode* root, int dist,
                      unordered_map<TreeNode*, int>& nodeToDist, int& minDist,
                      int& ans) {
    if (!root)
      return;
    if (nodeToDist.count(root))
      dist = nodeToDist[root];
    if (!root->left && !root->right) {  // is leaf
      if (dist < minDist) {
        minDist = dist;
        ans = root->val;
      }
      return;
    }

    getClosestLeaf(root->left, dist + 1, nodeToDist, minDist, ans);
    getClosestLeaf(root->right, dist + 1, nodeToDist, minDist, ans);
  }
};
