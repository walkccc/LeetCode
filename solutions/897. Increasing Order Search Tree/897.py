class Solution:
  def increasingBST(self, root: TreeNode, tail: TreeNode = None) -> TreeNode:
    if not root:
      return tail

    res = self.increasingBST(root.left, root)
    root.left = None
    root.right = self.increasingBST(root.right, tail)
    return res
