class Solution {
  public int diameter(Node root) {
    maxDepth(root);
    return ans;
  }

  private int ans = 0;

  private int maxDepth(Node root) {
    int max1 = 0;
    int max2 = 0;

    for (Node child : root.children) {
      final int depth = maxDepth(child);
      if (depth > max1) {
        max2 = max1;
        max1 = depth;
      } else if (depth > max2) {
        max2 = depth;
      }
    }

    ans = Math.max(ans, max1 + max2);
    return 1 + max1;
  }
}
