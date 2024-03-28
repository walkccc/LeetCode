class Solution:
  def insertIntoMaxTree(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
    if not root:
      return TreeNode(val)
    if root.val < val:
      return TreeNode(val, root, None)
    root.right = self.insertIntoMaxTree(root.right, val)
    return root
