class Solution:
  def kthSmallest(self, root: TreeNode | None, k: int) -> int:
    def countNodes(root: TreeNode | None) -> int:
      if not root:
        return 0
      return 1 + countNodes(root.left) + countNodes(root.right)

    leftCount = countNodes(root.left)

    if leftCount == k - 1:
      return root.val
    if leftCount >= k:
      return self.kthSmallest(root.left, k)
    return self.kthSmallest(root.right, k - 1 - leftCount)  # leftCount < k
