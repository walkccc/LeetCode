class Solution:
  def preorderTraversal(self, root: TreeNode | None) -> list[int]:
    ans = []

    def preorder(root: TreeNode | None) -> None:
      if not root:
        return

      ans.append(root.val)
      preorder(root.left)
      preorder(root.right)

    preorder(root)
    return ans
