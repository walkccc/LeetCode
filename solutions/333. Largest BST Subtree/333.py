from dataclasses import dataclass


@dataclass(frozen=True)
class T:
  mn: int  # the minimum value in the subtree
  mx: int  # the maximum value in the subtree
  size: int  # the size of the subtree


class Solution:
  def largestBSTSubtree(self, root: TreeNode | None) -> int:
    def dfs(root: TreeNode | None) -> T:
      if not root:
        return T(math.inf, -math.inf, 0)

      l = dfs(root.left)
      r = dfs(root.right)

      if l.mx < root.val < r.mn:
        return T(min(l.mn, root.val), max(r.mx, root.val), 1 + l.size + r.size)

      # Mark one as invalid, but still record the size of children.
      # Return (-inf, inf) because no node will be > inf or < -inf.
      return T(-math.inf, math.inf, max(l.size, r.size))

    return dfs(root).size
