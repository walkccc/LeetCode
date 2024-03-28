class Solution:
  def removeLeafNodes(self, root: Optional[TreeNode], target: int) -> Optional[TreeNode]:
    if not root:
      return None
    root.left = self.removeLeafNodes(root.left, target)
    root.right = self.removeLeafNodes(root.right, target)
    return None if self._isLeaf(root) and root.val == target else root

  def _isLeaf(self, root: Optional[TreeNode]) -> bool:
    return not root.left and not root.right
