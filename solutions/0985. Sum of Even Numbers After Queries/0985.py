class Solution:
  def sumEvenAfterQueries(self, nums: List[int], queries: List[List[int]]) -> List[int]:
    ans = []
    summ = sum(a for a in nums if a % 2 == 0)

    for val, index in queries:
      if nums[index] % 2 == 0:
        summ -= nums[index]
      nums[index] += val
      if nums[index] % 2 == 0:
        summ += nums[index]
      ans.append(summ)

    return ans
