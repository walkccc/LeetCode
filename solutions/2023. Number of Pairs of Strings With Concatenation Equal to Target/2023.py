class Solution:
  def numOfPairs(self, nums: list[str], target: str) -> int:
    ans = 0
    count = collections.Counter()

    for num in nums:
      k = len(num)
      if target[:k] == num:
        ans += count[target[k:]]
      if target[-k:] == num:
        ans += count[target[:-k]]
      count[num] += 1

    return ans
