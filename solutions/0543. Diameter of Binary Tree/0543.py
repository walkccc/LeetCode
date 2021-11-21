class Solution:
  def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
    self.ans = 0

    def maxDepth(root: Optional[TreeNode]) -> int:
      if not root:
        return 0

      l = maxDepth(root.left)
      r = maxDepth(root.right)
      self.ans = max(self.ans, l + r)

      return 1 + max(l, r)

    maxDepth(root)

    return self.ans
