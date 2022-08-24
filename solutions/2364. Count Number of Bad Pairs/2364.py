class Solution:
  def countBadPairs(self, nums: List[int]) -> int:
    ans = 0
    count = Counter()  # (nums[i] - i)

    for i, num in enumerate(nums):
      #     count[nums[i] - i] := # of good pairs
      # i - count[nums[i] - i] := # of bad pairs
      ans += i - count[num - i]
      count[num - i] += 1

    return ans
