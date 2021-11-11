class Solution:
  def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
    def inorder(root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
      if not root:
        return []

      return inorder(root.left) + [root.val] + inorder(root.right)

    return inorder(root)[k - 1]
