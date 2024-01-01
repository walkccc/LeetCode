class Solution:
  def isBalanced(self, root: Optional[TreeNode]) -> bool:
    ans = True

    def maxDepth(root: Optional[TreeNode]) -> int:
      """Returns the height of root and sets ans to false if root unbalanced."""
      nonlocal ans
      if not root or not ans:
        return 0
      left = maxDepth(root.left)
      right = maxDepth(root.right)
      if abs(left - right) > 1:
        ans = False
      return max(left, right) + 1

    maxDepth(root)
    return ans
