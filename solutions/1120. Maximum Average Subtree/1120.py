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

      l = maximumAverage(root.left)
      r = maximumAverage(root.right)

      summ = root.val + l.summ + r.summ
      count = 1 + l.count + r.count
      maxAverage = max(summ / count, l.maxAverage, r.maxAverage)
      return T(summ, count, maxAverage)

    return maximumAverage(root).maxAverage
