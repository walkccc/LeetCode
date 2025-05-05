class Solution:
  def hasPathSum(self, root: TreeNode, summ: int) -> bool:
    if not root:
      return False
    if root.val == summ and not root.left and not root.right:
      return True
    return (self.hasPathSum(root.left, summ - root.val) or
            self.hasPathSum(root.right, summ - root.val))
