class Solution:
  # Similar to 1526. Minimum Number of Increments on Subarrays to Form a Target Array
  def minimumOperations(self, nums: list[int], target: list[int]) -> int:
    ans = abs(nums[0] - target[0])

    for (prevNum, prevTarget), (currNum, currTarget) in (
        itertools.pairwise(zip(nums, target))
    ):
      currDiff = currTarget - currNum
      prevDiff = prevTarget - prevNum
      if currDiff >= 0 and prevDiff >= 0:
        ans += max(0, currDiff - prevDiff)
      elif currDiff <= 0 and prevDiff <= 0:
        ans += max(0, abs(currDiff) - abs(prevDiff))
      else:
        ans += abs(currDiff)

    return ans
