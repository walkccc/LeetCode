class Solution:
  # Similar to 3265. Count Almost Equal Pairs I
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
    """Returns all possible numbers after 1 or 2 swaps."""
    n = len(digits)
    swaps = set([int(''.join(digits))])

    # Add all numbers after 1 swap.
    for i, j in itertools.combinations(range(n), 2):
      newDigits = digits[:]
      newDigits[i], newDigits[j] = newDigits[j], newDigits[i]
      swaps.add(int(''.join(newDigits)))

    # Add all numbers after 2 swaps.
    for (i1, j1), (i2, j2) in itertools.combinations(
            itertools.combinations(range(n), 2), 2):
      newDigits = digits[:]
      newDigits[i1], newDigits[j1] = newDigits[j1], newDigits[i1]
      newDigits[i2], newDigits[j2] = newDigits[j2], newDigits[i2]
      swaps.add(int(''.join(newDigits)))

    return swaps
