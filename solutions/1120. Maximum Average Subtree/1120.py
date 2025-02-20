from dataclasses import dataclass


@dataclass(frozen=True)
class T:
  summ: int
  count: int
  maxAverage: int


class Solution:
  def maximumAverageSubtree(self, root: TreeNode | None) -> float:
    def maximumAverage(root: TreeNode | None) -> T:
      if not root:
        return T(0, 0, 0)

      left = maximumAverage(root.left)
      right = maximumAverage(root.right)

      summ = root.val + left.summ + right.summ
      count = 1 + left.count + right.count
      maxAverage = max(summ / count, left.maxAverage, right.maxAverage)
      return T(summ, count, maxAverage)

    return maximumAverage(root).maxAverage
