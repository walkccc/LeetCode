class Solution {
 public:
  int diameter(Node* root) {
    int ans = 0;
    maxDepth(root, ans);
    return ans;
  }

 private:
  int maxDepth(Node* root, int& ans) {
    int max1 = 0;
    int max2 = 0;

    for (Node* child : root->children) {
      const int depth = maxDepth(child, ans);
      if (depth > max1) {
        max2 = max1;
        max1 = depth;
      } else if (depth > max2) {
        max2 = depth;
      }
    }

    ans = max(ans, max1 + max2);
    return 1 + max1;
  }
};
