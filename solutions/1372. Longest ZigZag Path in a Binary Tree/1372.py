from dataclasses import dataclass


@dataclass(frozen=True)
class T:
  leftMax: int
  rightMax: int
  subtreeMax: int


class Solution:
  def longestZigZag(self, root: TreeNode | None) -> int:
    def dfs(root: TreeNode | None) -> T:
      if not root:
        return T(-1, -1, -1)
      left = dfs(root.left)
      right = dfs(root.right)
      leftZigZag = left.rightMax + 1
      rightZigZag = right.leftMax + 1
      subtreeMax = max(leftZigZag, rightZigZag,
                       left.subtreeMax, right.subtreeMax)
      return T(leftZigZag, rightZigZag, subtreeMax)

    return dfs(root).subtreeMax
