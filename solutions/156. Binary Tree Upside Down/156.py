class Solution:
  def upsideDownBinaryTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
    if not root or not root.left:
      return root

    newRoot = self.upsideDownBinaryTree(root.left)
    root.left.left = root.right  # 2's left = 3 (root's right)
    root.left.right = root  # 2's right = 1 (root)
    root.left = None
    root.right = None
    return newRoot
