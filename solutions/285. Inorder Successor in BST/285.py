class Solution:
  def inorderSuccessor(self, root: Optional[TreeNode], p: Optional[TreeNode]) -> Optional[TreeNode]:
    if not root:
      return None
    if root.val <= p.val:
      return self.inorderSuccessor(root.right, p)
    return self.inorderSuccessor(root.left, p) or root
