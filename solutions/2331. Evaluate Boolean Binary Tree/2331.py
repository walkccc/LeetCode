class Solution:
  def evaluateTree(self, root: Optional[TreeNode]) -> bool:
    if root.val < 2:
      return root.val
    if root.val == 2:  # OR
      return self.evaluateTree(root.left) or self.evaluateTree(root.right)
    # AND
    return self.evaluateTree(root.left) and self.evaluateTree(root.right)
