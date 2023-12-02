class Solution:
  def findMaximumLength(self, nums: List[int]) -> int:
    n = len(nums)
    # prefix[i] := the sum of the first i nums
    prefix = list(itertools.accumulate(nums, initial=0))
    # dp[i] := the maximum number of elements in the increasing
    # sequence after processing the first i nums
    dp = [0] * (n + 1)
    # bestLeft[i] := the index l s.t. merging nums[l..i) is the
    # optimal strategy among processing the first i nums
    bestLeft = [0] * (n + 2)

    for i in range(1, n + 1):
      bestLeft[i] = max(bestLeft[i], bestLeft[i - 1])
      # When merging nums[l, i), consider the next segment as [i, r).
      # Find the minimum `r` where sum(nums[l, i)) <= sum(nums[i, r)).
      # Equivalently, prefix[i] - prefix[l] <= prefix[r] - prefix[i].
      #            => prefix[r] >= prefix[i] * 2 - prefix[l]
      # Therefore, we can binary search `prefix` to find the minimum `r`.
      l = bestLeft[i]
      r = bisect.bisect_left(prefix, 2 * prefix[i] - prefix[l])
      dp[i] = dp[l] + 1
      bestLeft[r] = i

    return dp[n]
