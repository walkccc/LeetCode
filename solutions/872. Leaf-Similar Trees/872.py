class Solution:
  def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
    def dfs(root: Optional[TreeNode]) -> None:
      if not root:
        return
      if not root.left and not root.right:
        yield root.val
        return

      yield from dfs(root.left)
      yield from dfs(root.right)

    return list(dfs(root1)) == list(dfs(root2))
