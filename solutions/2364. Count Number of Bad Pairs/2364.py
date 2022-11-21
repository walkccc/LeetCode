class Solution:
  def countBadPairs(self, nums: List[int]) -> int:
    ans = 0
    count = Counter()  # (nums[i] - i)

    for i, num in enumerate(nums):
      #     count[nums[i] - i] := # Of good pairs
      # I - count[nums[i] - i] := # Of bad pairs
      ans += i - count[num - i]
      count[num - i] += 1

    return ans
