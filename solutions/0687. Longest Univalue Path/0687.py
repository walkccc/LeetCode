class Solution:
  def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
    ans = 0

    def longestUnivaluePathDownFrom(root: Optional[TreeNode]) -> int:
      nonlocal ans
      if not root:
        return 0

      l = longestUnivaluePathDownFrom(root.left)
      r = longestUnivaluePathDownFrom(root.right)
      arrowLeft = l + 1 if root.left and root.left.val == root.val else 0
      arrowRight = r + 1 if root.right and root.right.val == root.val else 0
      ans = max(ans, arrowLeft + arrowRight)
      return max(arrowLeft, arrowRight)

    longestUnivaluePathDownFrom(root)
    return ans
