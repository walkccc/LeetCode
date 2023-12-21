class Solution:
  def findMaximumXOR(self, nums: List[int]) -> int:
    maxNum = max(nums)
    if maxNum == 0:
      return 0
    maxBit = int(math.log2(maxNum))
    ans = 0
    mask = 0

    # If ans is 11100 when i = 2, it means that before we reach the last two
    # bits, 11100 is the maximum XOR we have, and we're going to explore if we
    # can get another two 1s and put them into the `ans`.
    for i in range(maxBit, -1, -1):
      # Mask grows like: 100...000, 110...000, 111...000, ..., 111...111.
      mask |= 1 << i
      # We only care about the left parts,
      # If i = 2, nums = [1110, 1011, 0111]
      #    -> prefixes = [1100, 1000, 0100]
      prefixes = set([num & mask for num in nums])
      # If i = 1 and before this iteration, the ans is 10100, it means that we
      # want to grow the ans to 10100 | 1 << 1 = 10110 and we're looking for
      # XOR of two prefixes = candidate.
      candidate = ans | 1 << i
      for prefix in prefixes:
        if prefix ^ candidate in prefixes:
          ans = candidate
          break

    return ans
