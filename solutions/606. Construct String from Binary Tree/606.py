class Solution:
  def tree2str(self, t: TreeNode | None) -> str:
    def dfs(root: TreeNode | None) -> str:
      if not root:
        return ''
      if root.right:
        return str(root.val) + '(' + dfs(root.left) + ')(' + dfs(root.right) + ')'
      if root.left:
        return str(root.val) + '(' + dfs(root.left) + ')'
      return str(root.val)
    return dfs(t)
