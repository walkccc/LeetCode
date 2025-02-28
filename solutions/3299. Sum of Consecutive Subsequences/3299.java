class Solution {
  public int getSum(int[] nums) {
    final long increasingSequenceSum = getSequenceSum(nums, 1);
    final long decreasingSequenceSum = getSequenceSum(nums, -1);
    final long arraySum = getArraySum(nums);
    return (int) ((increasingSequenceSum + decreasingSequenceSum - arraySum + kMod) % kMod);
  }

  private static final int kMod = 1_000_000_007;

  // Returns the sum of all sequences in the array that are in consecutive
  // increasing order if `direction` is 1, or in consecutive decreasing order if
  // `direction` is -1.
  private long getSequenceSum(int[] nums, int direction) {
    int n = nums.length;
    long sequenceSum = 0;
    // {num: the number of subsequences ending in `num` so far}
    Map<Integer, Integer> prefixCount = new HashMap<>();
    // {num: the number of subsequences starting from `num` so far}
    Map<Integer, Integer> suffixCount = new HashMap<>();
    // prefixSubseqs[i] := the number of subsequences ending in nums[i]
    int[] prefixSubseqs = new int[n];
    // suffixSubseqs[i] := the number of subsequences starting from nums[i]
    int[] suffixSubseqs = new int[n];

    for (int i = 0; i < n; ++i) {
      final int prevNum = nums[i] - direction;
      final int subseqsCount = prefixCount.getOrDefault(prevNum, 0) + 1;
      prefixSubseqs[i] = subseqsCount;
      prefixCount.merge(nums[i], subseqsCount, Integer::sum);
      prefixCount.put(nums[i], prefixCount.get(nums[i]) % kMod);
    }

    for (int i = n - 1; i >= 0; --i) {
      int nextNum = nums[i] + direction;
      int subseqsCount = suffixCount.getOrDefault(nextNum, 0) + 1;
      suffixSubseqs[i] = subseqsCount;
      suffixCount.merge(nums[i], subseqsCount, Integer::sum);
      suffixCount.put(nums[i], suffixCount.get(nums[i]) % kMod);
    }

    for (int i = 0; i < n; ++i) {
      sequenceSum += (long) nums[i] * prefixSubseqs[i] % kMod * suffixSubseqs[i];
      sequenceSum %= kMod;
    }

    return sequenceSum;
  }

  private int getArraySum(int[] nums) {
    int arraySum = 0;
    for (int num : nums)
      arraySum = (arraySum + num) % kMod;
    return arraySum;
  }
}
