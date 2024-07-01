class Solution:
  def isBalanced(self, root: Optional[TreeNode]) -> bool:
    if not root:
      return True

    def maxDepth(root: Optional[TreeNode]) -> int:
      if not root:
        return 0
      return 1 + max(maxDepth(root.left), maxDepth(root.right))

    return abs(maxDepth(root.left) - maxDepth(root.right)) <= 1 and \
        self.isBalanced(root.left) and self.isBalanced(root.right)
