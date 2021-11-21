class Solution:
  def flatten(self, root: Optional[TreeNode]) -> None:
    def flattenedTail(root: Optional[TreeNode]) -> Optional[TreeNode]:
      """
      return the tail of root after root is flattened
      """
      if not root:
        return None
      if not root.left and not root.right:
        return root

      leftTail = flattenedTail(root.left)
      rightTail = flattenedTail(root.right)

      if leftTail:
        leftTail.right = root.right
        root.right = root.left
        root.left = None

      return rightTail if rightTail else leftTail

    flattenedTail(root)
