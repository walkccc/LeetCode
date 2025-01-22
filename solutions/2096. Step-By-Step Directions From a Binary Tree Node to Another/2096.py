class Solution:
  def getDirections(
      self,
      root: TreeNode | None,
      startValue: int,
      destValue: int,
  ) -> str:
    def lca(root: TreeNode | None) -> TreeNode | None:
      if not root or root.val in (startValue, destValue):
        return root
      left = lca(root.left)
      right = lca(root.right)
      if left and right:
        return root
      return left or right

    def dfs(root: TreeNode | None, path: list[str]) -> None:
      if not root:
        return
      if root.val == startValue:
        self.pathToStart = ''.join(path)
      if root.val == destValue:
        self.pathToDest = ''.join(path)
      path.append('L')
      dfs(root.left, path)
      path.pop()
      path.append('R')
      dfs(root.right, path)
      path.pop()

    dfs(lca(root), [])  # Only this subtree matters.
    return 'U' * len(self.pathToStart) + ''.join(self.pathToDest)
