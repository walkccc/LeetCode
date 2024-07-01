class Solution:
  def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
    prefix = 0

    def reversedInorder(root: Optional[TreeNode]) -> None:
      nonlocal prefix
      if not root:
        return

      reversedInorder(root.right)
      prefix += root.val
      root.val = prefix
      reversedInorder(root.left)

    reversedInorder(root)
    return root
