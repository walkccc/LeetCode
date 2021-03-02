class Solution:
  def kthSmallest(self, root: TreeNode, k: int) -> int:
    def inorder(root: TreeNode) -> List[TreeNode]:
      if not root:
        return []

      return inorder(root.left) + [root.val] + inorder(root.right)

    return inorder(root)[k - 1]
