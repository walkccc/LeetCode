class Solution {
  public char getKthCharacter(RopeTreeNode root, int k) {
    while (root.len > 0) {
      final int leftLen = root.left == null ? 0 : Math.max(root.left.len, root.left.val.length());
      if (leftLen >= k) {
        root = root.left;
      } else {
        root = root.right;
        k -= leftLen;
      }
    }
    return root.val.charAt(k - 1);
  }
}
