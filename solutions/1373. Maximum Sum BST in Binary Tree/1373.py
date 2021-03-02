class Solution:
  def maxSumBST(self, root: TreeNode) -> int:
    def dfs(root: TreeNode) -> tuple:
      if not root:
        return inf, -inf, 0, True

      leftMin, leftMax, leftSum, leftValid = dfs(root.left)
      rightMin, rightMax, rightSum, rightValid = dfs(root.right)
      valid = leftValid and rightValid and root.val > leftMax and root.val < rightMin
      summ = root.val + leftSum + rightSum if valid else -1
      self.ans = max(self.ans, summ)

      return min(root.val, leftMin), max(root.val, rightMax), summ, valid

    self.ans = 0

    dfs(root)

    return self.ans
