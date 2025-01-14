class Solution:
  def minChanges(self, nums: list[int], k: int) -> int:
    pairSize = len(nums) // 2
    diffCount = collections.Counter()  # {nums[-i - 1] - nums[i]: freq}
    # oneChangeCount[i] := the number of pairs that need only one change to
    # to achieve a difference of `i`
    oneChangeCount = [0] * (k + 1)

    for i in range(pairSize):
      a = nums[i]
      b = nums[-i - 1]
      diffCount[abs(a - b)] += 1
      oneChangeCount[max(a, b, k - a, k - b)] += 1

    # prefixOneChangeCount[i] := the number of pairs that need only one change
    # to achieve a difference >= `i`
    # prefixOneChangeCount[i] = sum(oneChangeCount[i..k])
    prefixOneChangeCount = list(
        itertools.accumulate(reversed(oneChangeCount)))[::-1]

    return min(prefixOneChangeCount[diff] - freq +  # one change
               (pairSize - prefixOneChangeCount[diff]) * 2  # two changes
               for diff, freq in diffCount.items())
