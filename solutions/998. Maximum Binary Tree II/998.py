class Solution:
  def insertIntoMaxTree(
      self,
      root: TreeNode | None,
      val: int,
  ) -> TreeNode | None:
    if not root:
      return TreeNode(val)
    if root.val < val:
      return TreeNode(val, root, None)
    root.right = self.insertIntoMaxTree(root.right, val)
    return root
