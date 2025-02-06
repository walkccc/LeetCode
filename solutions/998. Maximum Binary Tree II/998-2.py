class Solution:
  def insertIntoMaxTree(
      self,
      root: TreeNode | None,
      val: int,
  ) -> TreeNode | None:
    if root.val < val:
      return TreeNode(val, root, None)
    curr = root
    while curr.right and curr.right.val > val:
      curr = curr.right
    inserted = TreeNode(val, curr.right, None)
    curr.right = inserted
    return root
