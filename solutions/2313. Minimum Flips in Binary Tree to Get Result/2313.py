class Solution:
  def minimumFlips(self, root: Optional[TreeNode], result: bool) -> int:
    # dp(root, target) := min flips to make the subtree root become target
    @functools.lru_cache(None)
    def dp(root: Optional[TreeNode], target: bool) -> int:
      if root.val in (0, 1):  # leaf
        return 0 if root.val == target else 1
      if root.val == 5:  # NOT
        return dp(root.left or root.right, not target)
      if root.val == 2:  # OR
        nextTargets = [(0, 1), (1, 0), (1, 1)] if target else [[0, 0]]
      elif root.val == 3:  # AND
        nextTargets = [(1, 1)] if target else [(0, 0), (0, 1), (1, 0)]
      else:  # root.val == 4 XOR
        nextTargets = [(0, 1), (1, 0)] if target else [(0, 0), (1, 1)]
      return min(dp(root.left, leftTarget) + dp(root.right, rightTarget)
                 for leftTarget, rightTarget in nextTargets)

    return dp(root, result)
