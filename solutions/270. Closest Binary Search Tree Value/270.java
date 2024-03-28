class Solution {
  public int closestValue(TreeNode root, double target) {
    // If target < root.val, search the left subtree.
    if (target < root.val && root.left != null) {
      final int left = closestValue(root.left, target);
      if (Math.abs(left - target) < Math.abs(root.val - target))
        return left;
    }

    // If target > root.val, search the right subtree.
    if (target > root.val && root.right != null) {
      final int right = closestValue(root.right, target);
      if (Math.abs(right - target) < Math.abs(root.val - target))
        return right;
    }

    return root.val;
  }
}
