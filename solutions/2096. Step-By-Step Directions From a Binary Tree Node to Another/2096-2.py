class Solution:
  def getDirections(
      self,
      root: TreeNode | None,
      startValue: int,
      destValue: int,
  ) -> str:
    def dfs(root: TreeNode | None, val: int, path: list[str]) -> bool:
      """Builds the string in reverse order to avoid creating a new copy."""
      if root.val == val:
        return True
      if root.left and dfs(root.left, val, path):
        path.append('L')
      elif root.right and dfs(root.right, val, path):
        path.append('R')
      return len(path) > 0

    pathToStart = []
    pathToDest = []

    dfs(root, startValue, pathToStart)
    dfs(root, destValue, pathToDest)

    while pathToStart and pathToDest and pathToStart[-1] == pathToDest[-1]:
      pathToStart.pop()
      pathToDest.pop()

    return 'U' * len(pathToStart) + ''.join(reversed(pathToDest))
