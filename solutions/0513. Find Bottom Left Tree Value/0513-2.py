class Solution:
  def findBottomLeftValue(self, root: TreeNode) -> int:
    self.ans = 0
    self.maxDepth = 0

    def dfs(root: TreeNode, depth: int) -> None:
      if not root:
        return
      if depth > self.maxDepth:
        self.maxDepth = depth
        self.ans = root.val

      dfs(root.left, depth + 1)
      dfs(root.right, depth + 1)

    dfs(root, 1)

    return self.ans
