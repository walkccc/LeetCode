class Solution:
  def subsequenceCount(self, nums: list[int]) -> int:
    kMod = 1_000_000_007
    even = 0  # the number of subsequences with even sum
    odd = 0  # the number of subsequences with odd sum

    for num in nums:
      if num % 2 == 0:
        # Appending an even number to a subsequence doesn't change the parity.
        # The even number itself is also a valid subsequence.
        even, odd = even + even + 1, odd + odd
      else:
        # Appending an odd number to a subsequence changes the parity.
        # The odd number itself is also a valid subsequence.
        even, odd = even + odd, odd + even + 1

    return odd % kMod
