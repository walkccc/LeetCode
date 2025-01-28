class Solution:
  def findBottomLeftValue(self, root: TreeNode | None) -> int:
    ans = 0
    maxDepth = 0

    def dfs(root: TreeNode | None, depth: int) -> None:
      nonlocal ans
      nonlocal maxDepth
      if not root:
        return
      if depth > maxDepth:
        maxDepth = depth
        ans = root.val

      dfs(root.left, depth + 1)
      dfs(root.right, depth + 1)

    dfs(root, 1)
    return ans
