class Solution:
  def kthSmallest(self, root: TreeNode | None, k: int) -> int:
    rank = 0
    ans = 0

    def traverse(root: TreeNode | None) -> None:
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
