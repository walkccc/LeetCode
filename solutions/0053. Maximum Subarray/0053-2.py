class Solution:
  def maxSubArray(self, nums: List[int]) -> int:
    def divideAndConquer(l: int, r: int) -> Tuple[int, int, int, int]:
      if l == r:
        return nums[l], nums[l], nums[l], nums[l]

      m = (l + r) // 2
      t1 = divideAndConquer(l, m)
      t2 = divideAndConquer(m + 1, r)

      left = max(t1[0], t1[3] + t2[0])
      right = max(t1[1] + t2[3], t2[1])
      mid = max(t1[1] + t2[0], max(t1[2], t2[2]))
      summ = t1[3] + t2[3]
      return left, right, mid, summ

    return divideAndConquer(0, len(nums) - 1)[2]
