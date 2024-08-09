class Solution:
  def pruneTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
    if not root:
      return None
    root.left = self.pruneTree(root.left)
    root.right = self.pruneTree(root.right)
    if not root.left and not root.right and not root.val:
      return None
    return root
