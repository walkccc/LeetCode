class Solution:
  def findLeaves(self, root: Optional[TreeNode]) -> List[List[int]]:
    ans = []

    def depth(root: Optional[TreeNode]) -> int:
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
