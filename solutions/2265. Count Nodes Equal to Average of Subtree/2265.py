class Solution:
  def averageOfSubtree(self, root: Optional[TreeNode]) -> int:
    ans = 0

    def dfs(root: Optional[TreeNode]) -> Tuple[int, int]:
      nonlocal ans
      if not root:
        return (0, 0)
      leftSum, leftCount = dfs(root.left)
      rightSum, rightCount = dfs(root.right)
      summ = root.val + leftSum + rightSum
      count = 1 + leftCount + rightCount
      if summ // count == root.val:
        ans += 1
      return (summ, count)

    dfs(root)
    return ans
