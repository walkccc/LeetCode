class Solution:
  def closestValue(self, root: TreeNode | None, target: float) -> int:
    # If target < root.val, search the left subtree.
    if target < root.val and root.left:
      left = self.closestValue(root.left, target)
      if abs(left - target) <= abs(root.val - target):
        return left

    # If target > root.val, search the right subtree.
    if target > root.val and root.right:
      right = self.closestValue(root.right, target)
      if abs(right - target) < abs(root.val - target):
        return right

    return root.val
