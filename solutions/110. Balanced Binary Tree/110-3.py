class Solution:
  def isBalanced(self, root: TreeNode | None) -> bool:
    def maxDepth(root: TreeNode | None) -> int:
      """Returns the height of root if root is balanced; otherwise, returns -1."""
      if not root:
        return 0

      left = maxDepth(root.left)
      if left == -1:
        return -1
      right = maxDepth(root.right)
      if right == -1:
        return -1
      if abs(left - right) > 1:
        return -1

      return 1 + max(maxDepth(root.left), maxDepth(root.right))

    return maxDepth(root) != -1
