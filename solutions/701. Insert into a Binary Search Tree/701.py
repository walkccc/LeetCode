class Solution:
  def insertIntoBST(self, root: TreeNode | None, val: int) -> TreeNode | None:
    if not root:
      return TreeNode(val)
    if root.val > val:
      root.left = self.insertIntoBST(root.left, val)
    else:
      root.right = self.insertIntoBST(root.right, val)
    return root
