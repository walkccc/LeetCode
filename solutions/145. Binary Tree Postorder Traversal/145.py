class Solution:
  def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
    ans = []

    def postorder(root: Optional[TreeNode]) -> None:
      if not root:
        return

      postorder(root.left)
      postorder(root.right)
      ans.append(root.val)

    postorder(root)
    return ans
