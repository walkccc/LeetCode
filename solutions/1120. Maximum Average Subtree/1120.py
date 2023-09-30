class T:
  def __init__(self, summ: int, count: int, maxAverage: float):
    self.summ = summ
    self.count = count
    self.maxAverage = maxAverage


class Solution:
  def maximumAverageSubtree(self, root: Optional[TreeNode]) -> float:
    def maximumAverage(root: Optional[TreeNode]) -> T:
      if not root:
        return T(0, 0, 0)

      left = maximumAverage(root.left)
      right = maximumAverage(root.right)

      summ = root.val + left.summ + right.summ
      count = 1 + left.count + right.count
      maxAverage = max(summ / count, left.maxAverage, right.maxAverage)
      return T(summ, count, maxAverage)

    return maximumAverage(root).maxAverage
