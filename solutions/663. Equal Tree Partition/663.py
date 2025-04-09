class Solution:
  def checkEqualTree(self, root: TreeNode | None) -> bool:
    if not root:
      return False

    seen = set()

    def dfs(root: TreeNode | None) -> int:
      if not root:
        return 0

      summ = root.val + dfs(root.left) + dfs(root.right)
      seen.add(summ)
      return summ

    summ = root.val + dfs(root.left) + dfs(root.right)
    return summ % 2 == 0 and summ // 2 in seen
