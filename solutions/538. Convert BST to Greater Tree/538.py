class Solution:
  def convertBST(self, root: TreeNode | None) -> TreeNode | None:
    prefix = 0

    def reversedInorder(root: TreeNode | None) -> None:
      nonlocal prefix
      if not root:
        return

      reversedInorder(root.right)
      prefix += root.val
      root.val = prefix
      reversedInorder(root.left)

    reversedInorder(root)
    return root
