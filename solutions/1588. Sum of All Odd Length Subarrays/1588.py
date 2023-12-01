class Solution:
  def sumOddLengthSubarrays(self, arr: List[int]) -> int:
    ans = 0
    # Maintain two sums of subarrays ending in the previous index.
    # Each time we meet a new number, we'll consider 'how many times' it should
    # contribute to the newly built subarrays by calculating the number of
    # previous even/odd-length subarrays.
    prevEvenSum = 0  # the sum of even-length subarrays
    prevOddSum = 0  # the sum of odd-length subarrays

    for i, a in enumerate(arr):
      # (i + 1) // 2 := the number of previous odd-length subarrays.
      currEvenSum = prevOddSum + ((i + 1) // 2) * a
      # i // 2 + 1 := the number of previous even-length subarrays
      # (including 0).
      currOddSum = prevEvenSum + (i // 2 + 1) * a
      ans += currOddSum
      prevEvenSum = currEvenSum
      prevOddSum = currOddSum

    return ans
