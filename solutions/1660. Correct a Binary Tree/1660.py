class Solution:
  def __init__(self):
    self.seen = set()

  def correctBinaryTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
    if root == None:
      return None
    if root.right and root.right.val in self.seen:
      return None
    self.seen.add(root.val)
    root.right = self.correctBinaryTree(root.right)
    root.left = self.correctBinaryTree(root.left)
    return root
