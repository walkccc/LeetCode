class Solution:
  def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
    rank = 0
    ans = 0

    def traverse(root: Optional[TreeNode]) -> None:
      nonlocal rank
      nonlocal ans
      if not root:
        return

      traverse(root.left)
      rank += 1
      if rank == k:
        ans = root.val
        return
      traverse(root.right)

    traverse(root)
    return ans
