class Solution:
  def lengthOfLIS(self, nums: list[int]) -> int:
    # tails[i] := the minimum tails of all the increasing subsequences having
    # length i + 1
    tails = []

    for num in nums:
      if not tails or num > tails[-1]:
        tails.append(num)
      else:
        tails[bisect.bisect_left(tails, num)] = num

    return len(tails)
