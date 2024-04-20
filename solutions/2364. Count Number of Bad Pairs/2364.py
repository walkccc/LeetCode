class Solution:
  def countBadPairs(self, nums: List[int]) -> int:
    ans = 0
    count = collections.Counter()  # (nums[i] - i)

    for i, num in enumerate(nums):
      #     count[nums[i] - i] := the number of good pairs
      # i - count[nums[i] - i] := the number of bad pairs
      ans += i - count[num - i]
      count[num - i] += 1

    return ans
