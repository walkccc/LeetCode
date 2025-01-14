class Solution:
  def inorderSuccessor(
      self,
      root: TreeNode | None,
      p: TreeNode | None,
  ) -> TreeNode | None:
    if not root:
      return None
    if root.val <= p.val:
      return self.inorderSuccessor(root.right, p)
    return self.inorderSuccessor(root.left, p) or root
