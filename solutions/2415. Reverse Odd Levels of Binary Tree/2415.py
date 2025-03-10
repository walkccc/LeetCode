class Solution:
  def reverseOddLevels(self, root: TreeNode | None) -> TreeNode | None:
    def dfs(left: TreeNode | None, right: TreeNode | None, isOddLevel: bool) -> None:
      if not left:
        return
      if isOddLevel:
        left.val, right.val = right.val, left.val
      dfs(left.left, right.right, not isOddLevel)
      dfs(left.right, right.left, not isOddLevel)

    dfs(root.left, root.right, True)
    return root
