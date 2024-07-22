from dataclasses import dataclass


@dataclass(frozen=True)
class T:
  min: int  # the minimum value in the subtree
  max: int  # the maximum value in the subtree
  size: int  # the size of the subtree


class Solution:
  def largestBSTSubtree(self, root: Optional[TreeNode]) -> int:
    def dfs(root: Optional[TreeNode]) -> T:
      if not root:
        return T(math.inf, -math.inf, 0)

      l = dfs(root.left)
      r = dfs(root.right)

      if l.max < root.val < r.min:
        return T(min(l.min, root.val), max(r.max, root.val), 1 + l.size + r.size)

      # Mark one as invalid, but still record the size of children.
      # Return (-inf, inf) because no node will be > inf or < -inf.
      return T(-math.inf, math.inf, max(l.size, r.size))

    return dfs(root).size
