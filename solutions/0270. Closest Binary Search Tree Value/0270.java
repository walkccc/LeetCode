class Solution {
  public int closestValue(TreeNode root, double target) {
    // if target < root.val, search left subtree
    if (target < root.val && root.left != null) {
      final int left = closestValue(root.left, target);
      if (Math.abs(left - target) < Math.abs(root.val - target))
        return left;
    }

    // if target > root.val, search right subtree
    if (target > root.val && root.right != null) {
      final int right = closestValue(root.right, target);
      if (Math.abs(right - target) < Math.abs(root.val - target))
        return right;
    }

    return root.val;
  }
}
