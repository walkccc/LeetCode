class Solution:
  def maxPathSum(self, root: TreeNode) -> int:
    self.ans = -inf

    def maxPathSumDownFrom(root: TreeNode) -> int:
      if not root:
        return 0

      l = max(maxPathSumDownFrom(root.left), 0)
      r = max(maxPathSumDownFrom(root.right), 0)
      self.ans = max(self.ans, root.val + l + r)

      return root.val + max(l, r)

    maxPathSumDownFrom(root)

    return self.ans
