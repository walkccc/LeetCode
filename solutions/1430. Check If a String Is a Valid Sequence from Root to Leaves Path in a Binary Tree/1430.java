class Solution {
  public boolean isValidSequence(TreeNode root, int[] arr) {
    return isValidSequence(root, arr, 0);
  }

  private boolean isValidSequence(TreeNode root, int[] arr, int i) {
    if (root == null)
      return false;
    if (i == arr.length - 1)
      return root.val == arr[i] && root.left == null && root.right == null;
    return root.val == arr[i] &&
        (isValidSequence(root.left, arr, i + 1) || isValidSequence(root.right, arr, i + 1));
  }
}
