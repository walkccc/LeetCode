class Solution:
  def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
    def dfs(left: Optional[TreeNode], right: Optional[TreeNode], isOddLevel: bool) -> None:
      if not left:
        return
      if isOddLevel:
        left.val, right.val = right.val, left.val
      dfs(left.left, right.right, not isOddLevel)
      dfs(left.right, right.left, not isOddLevel)

    dfs(root.left, root.right, True)
    return root
