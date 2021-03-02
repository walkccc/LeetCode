class Solution {
  public int findSecondMinimumValue(TreeNode root) {
    if (root == null)
      return -1;
    return findSecondMinimumValue(root, root.val);
  }

  private int findSecondMinimumValue(TreeNode root, int min) {
    if (root == null)
      return -1;
    if (root.val > min)
      return root.val;

    final int leftMin = findSecondMinimumValue(root.left, min);
    final int rightMin = findSecondMinimumValue(root.right, min);

    if (leftMin == -1 || rightMin == -1)
      return Math.max(leftMin, rightMin);
    return Math.min(leftMin, rightMin);
  }
}
