class Solution {
 public:
  int diameter(Node* root) {
    int ans = 0;
    maxDepth(root, ans);
    return ans;
  }

 private:
  // Returns the maximum depth of the subtree rooted at `root`.
  int maxDepth(Node* root, int& ans) {
    int maxSubDepth1 = 0;
    int maxSubDepth2 = 0;
    for (Node* child : root->children) {
      const int maxSubDepth = maxDepth(child, ans);
      if (maxSubDepth > maxSubDepth1) {
        maxSubDepth2 = maxSubDepth1;
        maxSubDepth1 = maxSubDepth;
      } else if (maxSubDepth > maxSubDepth2) {
        maxSubDepth2 = maxSubDepth;
      }
    }
    ans = max(ans, maxSubDepth1 + maxSubDepth2);
    return 1 + maxSubDepth1;
  }
};
