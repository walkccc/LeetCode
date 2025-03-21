class Solution:
  def countPairs(self, nums: list[int]) -> int:
    ans = 0
    count = collections.Counter()
    maxLen = len(str(max(nums)))

    for num in nums:
      digits = list(str(num).zfill(maxLen))
      for swap in self._getSwaps(digits):
        ans += count[swap]
      count[num] += 1

    return ans

  def _getSwaps(self, digits: str) -> set[int]:
    """Returns all possible numbers after 1 swap."""
    n = len(digits)
    swaps = set([int(''.join(digits))])

    for i, j in itertools.combinations(range(n), 2):
      newDigits = digits[:]
      newDigits[i], newDigits[j] = newDigits[j], newDigits[i]
      swaps.add(int(''.join(newDigits)))

    return swaps
