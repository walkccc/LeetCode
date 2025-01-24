class Solution {
  public int maxDepth(Node root) {
    if (root == null)
      return 0;

    int ans = 0;

    for (Node child : root.children)
      ans = Math.max(ans, maxDepth(child));

    return 1 + ans;
  }
}
