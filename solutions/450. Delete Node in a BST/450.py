class Solution:
  def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
    if not root:
      return None
    if root.val == key:
      if not root.left:
        return root.right
      if not root.right:
        return root.left
      minNode = self._getMin(root.right)
      root.right = self.deleteNode(root.right, minNode.val)
      minNode.left = root.left
      minNode.right = root.right
      root = minNode
    elif root.val < key:
      root.right = self.deleteNode(root.right, key)
    else:  # root.val > key
      root.left = self.deleteNode(root.left, key)
    return root

  def _getMin(self, node: Optional[TreeNode]) -> Optional[TreeNode]:
    while node.left:
      node = node.left
    return node
