class Solution:
  def checkEqualTree(self, root: Optional[TreeNode]) -> bool:
    if not root:
      return False

    seen = set()

    def dfs(root: Optional[TreeNode]) -> int:
      if not root:
        return 0

      sum = root.val + dfs(root.left) + dfs(root.right)
      seen.add(sum)
      return sum

    sum = root.val + dfs(root.left) + dfs(root.right)
    return sum % 2 == 0 and sum // 2 in seen
