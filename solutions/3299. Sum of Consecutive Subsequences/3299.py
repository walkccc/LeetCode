class Solution:
  def getSum(self, nums: list[int]) -> int:
    kMod = 1_000_000_007
    n = len(nums)

    def getSequenceSum(nums: list[int], direction: int) -> int:
      """
      Returns the sum of all sequences in the array that are in consecutive
      increasing order if `direction` is 1, or in consecutive decreasing order
      if `direction` is -1."""
      sequenceSum = 0
      # {num: the number of subsequences ending in `num` so far}
      prefixCount = collections.Counter()
      # {num: the number of subsequences starting from `num` so far}
      suffixCount = collections.Counter()
      # prefixSubseqs[i] := the number of subsequences ending in nums[i]
      prefixSubseqs = [0] * n
      # suffixSubseqs[i] := the number of subsequences starting from nums[i]
      suffixSubseqs = [0] * n

      for i, num in enumerate(nums):
        prevNum = num - direction
        freq = prefixCount[prevNum] + 1
        prefixSubseqs[i] = freq
        prefixCount[num] += freq
        prefixCount[num] %= kMod

      for i, num in reversed(list(enumerate(nums))):
        nextNum = num + direction
        freq = suffixCount[nextNum] + 1
        suffixSubseqs[i] = freq
        suffixCount[num] += freq
        suffixCount[num] %= kMod

      for num, prefixSubseq, suffixSubseq in zip(
              nums, prefixSubseqs, suffixSubseqs):
        sequenceSum += num * prefixSubseq * suffixSubseq
        sequenceSum %= kMod

      return sequenceSum

    increasingSequenceSum = getSequenceSum(nums, 1)
    decreasingSequenceSum = getSequenceSum(nums, -1)
    return (increasingSequenceSum + decreasingSequenceSum - sum(nums) + kMod) % kMod
