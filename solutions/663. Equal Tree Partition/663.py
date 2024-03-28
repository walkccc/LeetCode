class Solution:
  def checkEqualTree(self, root: Optional[TreeNode]) -> bool:
    if not root:
      return False

    seen = set()

    def dfs(root: Optional[TreeNode]) -> int:
      if not root:
        return 0

      summ = root.val + dfs(root.left) + dfs(root.right)
      seen.add(summ)
      return summ

    summ = root.val + dfs(root.left) + dfs(root.right)
    return summ % 2 == 0 and summ // 2 in seen
