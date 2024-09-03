class Solution:
  def searchBST(self, root: TreeNode | None, val: int) -> TreeNode | None:
    if not root:
      return None
    if root.val == val:
      return root
    if root.val > val:
      return self.searchBST(root.left, val)
    return self.searchBST(root.right, val)
