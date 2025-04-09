class Solution:
  def pruneTree(self, root: TreeNode | None) -> TreeNode | None:
    if not root:
      return None
    root.left = self.pruneTree(root.left)
    root.right = self.pruneTree(root.right)
    if not root.left and not root.right and not root.val:
      return None
    return root
