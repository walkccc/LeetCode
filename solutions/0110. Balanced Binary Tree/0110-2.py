class Solution:
  def isBalanced(self, root: Optional[TreeNode]) -> bool:
    if not root:
      return True

    def maxDepth(root: Optional[TreeNode]) -> int:
      if not root:
        return 0

      leftHeight = maxDepth(root.left)
      if leftHeight == -1:
        return -1
      rightHeight = maxDepth(root.right)
      if rightHeight == -1:
        return -1
      if abs(leftHeight - rightHeight) > 1:
        return -1

      return 1 + max(maxDepth(root.left), maxDepth(root.right))

    return maxDepth(root) != -1
