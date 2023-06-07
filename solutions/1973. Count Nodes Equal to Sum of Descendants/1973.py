from dataclasses import dataclass


@dataclass(frozen=True)
class T:
  summ: int
  count: int


class Solution:
  def equalToDescendants(self, root: Optional[TreeNode]) -> int:
    def dfs(root: Optional[TreeNode]) -> T:
      if not root:
        return T(0, 0)
      left = dfs(root.left)
      right = dfs(root.right)
      return T(root.val + left.summ + right.summ,
               left.count + right.count +
               (1 if root.val == left.summ + right.summ else 0))

    return dfs(root).count
