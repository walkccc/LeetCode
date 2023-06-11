class Solution:
  def maximumSum(self, nums: List[int]) -> int:
    kMax = 9 * 9  # 999,999,999
    ans = -1
    count = [[] for _ in range(kMax + 1)]

    def getSum(num: int) -> int:
      summ = 0
      while num:
        summ += num % 10
        num //= 10
      return summ

    for num in nums:
      count[getSum(num)].append(num)

    for groupNums in count:
      if len(groupNums) < 2:
        continue
      groupNums.sort(reverse=True)
      ans = max(ans, groupNums[0] + groupNums[1])

    return ans
