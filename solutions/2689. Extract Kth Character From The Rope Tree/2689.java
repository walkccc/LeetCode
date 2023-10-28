class Solution {
  public char getKthCharacter(RopeTreeNode root, int k) {
    if (root.len == 0)
      return root.val.charAt(k - 1);
    final int leftLen = root.left == null ? 0 : Math.max(root.left.len, root.left.val.length());
    return leftLen >= k ? getKthCharacter(root.left, k) : getKthCharacter(root.right, k - leftLen);
  }
}
