from dataclasses import dataclass


@dataclass(frozen=True)
class T:
  left: int
  right: int
  mid: int
  summ: int


class Solution:
  def maxSubArray(self, nums: List[int]) -> int:
    def divideAndConquer(l: int, r: int) -> T:
      if l == r:
        return T(nums[l], nums[l], nums[l], nums[l])

      m = (l + r) // 2
      t1 = divideAndConquer(l, m)
      t2 = divideAndConquer(m + 1, r)

      left = max(t1.left, t1.summ + t2.left)
      right = max(t1.right + t2.summ, t2.right)
      mid = max(t1.right + t2.left, t1.mid, t2.mid)
      summ = t1.summ + t2.summ
      return T(left, right, mid, summ)

    return divideAndConquer(0, len(nums) - 1).mid
