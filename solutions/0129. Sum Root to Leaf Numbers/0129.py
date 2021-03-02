class Solution:
  def sumNumbers(self, root: TreeNode) -> int:
    self.ans = 0

    def dfs(root: TreeNode, path: int):
      if not root:
        return
      if not root.left and not root.right:
        self.ans += path * 10 + root.val
        return

      dfs(root.left, path * 10 + root.val)
      dfs(root.right, path * 10 + root.val)

    dfs(root, 0)

    return self.ans
