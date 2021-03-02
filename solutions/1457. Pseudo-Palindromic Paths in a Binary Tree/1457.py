class Solution:
  def pseudoPalindromicPaths(self, root: TreeNode) -> int:
    self.ans = 0

    def dfs(root: TreeNode, path: int) -> None:
      if not root:
        return
      if not root.left and not root.right:
        path ^= 1 << root.val
        if path & (path - 1) == 0:
          self.ans += 1
        return

      dfs(root.left, path ^ 1 << root.val)
      dfs(root.right, path ^ 1 << root.val)

    dfs(root, 0)

    return self.ans
