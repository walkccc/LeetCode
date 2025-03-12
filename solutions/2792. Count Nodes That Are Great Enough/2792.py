class Solution:
  def countGreatEnoughNodes(self, root: TreeNode | None, k: int) -> int:
    ans = 0

    def dfs(root: TreeNode | None) -> list[int]:
      nonlocal ans
      if not root:
        return []

      kSmallest = sorted(dfs(root.left) + dfs(root.right))[:k]
      if len(kSmallest) == k and root.val > kSmallest[-1]:
        ans += 1

      return kSmallest + [root.val]

    dfs(root)
    return ans
