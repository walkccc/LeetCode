class Solution:
  def findLeaves(self, root: TreeNode | None) -> list[list[int]]:
    ans = []

    def depth(root: TreeNode | None) -> int:
      """Returns the depth of the root (0-indexed)."""
      if not root:
        return -1

      l = depth(root.left)
      r = depth(root.right)
      h = 1 + max(l, r)

      if len(ans) == h:  # Meet a leaf
        ans.append([])

      ans[h].append(root.val)
      return h

    depth(root)
    return ans
