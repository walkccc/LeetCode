class Solution:
  def isBalanced(self, root: TreeNode | None) -> bool:
    if not root:
      return True

    def maxDepth(root: TreeNode | None) -> int:
      if not root:
        return 0
      return 1 + max(maxDepth(root.left), maxDepth(root.right))

    return (abs(maxDepth(root.left) - maxDepth(root.right)) <= 1 and
            self.isBalanced(root.left) and
            self.isBalanced(root.right))
