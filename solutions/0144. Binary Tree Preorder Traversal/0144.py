class Solution:
  def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
    ans = []

    def preorder(root: Optional[TreeNode]) -> None:
      if not root:
        return

      ans.append(root.val)
      preorder(root.left)
      preorder(root.right)

    preorder(root)
    return ans
