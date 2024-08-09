class Solution:
  def insertIntoMaxTree(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
    if root.val < val:
      return TreeNode(val, root, None)
    curr = root
    while curr.right and curr.right.val > val:
      curr = curr.right
    inserted = TreeNode(val, curr.right, None)
    curr.right = inserted
    return root
