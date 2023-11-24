class Solution:
  def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
    ans = []

    def dfs(root: Optional[TreeNode], path: List[str]) -> None:
      if not root:
        return
      if not root.left and not root.right:
        ans.append(''.join(path) + str(root.val))
        return

      path.append(str(root.val) + '->')
      dfs(root.left, path)
      dfs(root.right, path)
      path.pop()

    dfs(root, [])
    return ans
