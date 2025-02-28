class Solution {
  public int diameter(Node root) {
    maxDepth(root);
    return ans;
  }

  private int ans = 0;

  // Returns the maximum depth of the subtree rooted at `root`.
  private int maxDepth(Node root) {
    int maxSubDepth1 = 0;
    int maxSubDepth2 = 0;
    for (Node child : root.children) {
      final int maxSubDepth = maxDepth(child);
      if (maxSubDepth > maxSubDepth1) {
        maxSubDepth2 = maxSubDepth1;
        maxSubDepth1 = maxSubDepth;
      } else if (maxSubDepth > maxSubDepth2) {
        maxSubDepth2 = maxSubDepth;
      }
    }
    ans = Math.max(ans, maxSubDepth1 + maxSubDepth2);
    return 1 + maxSubDepth1;
  }
}
