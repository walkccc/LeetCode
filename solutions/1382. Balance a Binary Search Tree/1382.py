class Solution:
  def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
    nums = []

    def inorder(root: Optional[TreeNode]) -> None:
      if not root:
        return
      inorder(root.left)
      nums.append(root.val)
      inorder(root.right)

    inorder(root)

    # Same as 108. Convert Sorted Array to Binary Search Tree
    def build(l: int, r: int) -> Optional[TreeNode]:
      if l > r:
        return None
      m = (l + r) // 2
      return TreeNode(nums[m],
                      build(l, m - 1),
                      build(m + 1, r))

    return build(0, len(nums) - 1)
