class Solution:
  def minOperations(self, nums: list[int], target: int) -> int:
    kNoMissingBit = 31
    maxBit = 31
    ans = 0
    minMissingBit = kNoMissingBit
    # count[i] := the number of occurrences of 2^i
    count = collections.Counter(int(math.log2(num)) for num in nums)

    for bit in range(maxBit):
      # Check if `bit` is in the target.
      if target >> bit & 1:
        # If there are available bits, use one bit.
        if count[bit] > 0:
          count[bit] -= 1
        else:
          minMissingBit = min(minMissingBit, bit)
      # If we previously missed a bit and there are available bits.
      if minMissingBit != kNoMissingBit and count[bit] > 0:
        count[bit] -= 1
        # Count the operations to break `bit` into `minMissingBit`.
        ans += bit - minMissingBit
        minMissingBit = kNoMissingBit  # Set it to an the invalid value.
      # Combining smaller numbers costs nothing.
      count[bit + 1] += count[bit] // 2

    # Check if all target bits have been covered, otherwise return -1.
    return ans if minMissingBit == maxBit else -1
