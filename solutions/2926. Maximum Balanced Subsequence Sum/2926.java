class FenwickTree {
  public FenwickTree(int n) {
    vals = new long[n + 1];
  }

  // Updates the maximum the sum of subsequence ending in (i - 1) with `val`.
  public void update(int i, long val) {
    while (i < vals.length) {
      vals[i] = Math.max(vals[i], val);
      i += lowbit(i);
    }
  }

  // Returns the maximum the sum of subsequence ending in (i - 1).
  public long get(int i) {
    long res = 0;
    while (i > 0) {
      res = Math.max(res, vals[i]);
      i -= lowbit(i);
    }
    return res;
  }

  private long[] vals;

  private static int lowbit(int i) {
    return i & -i;
  }
}

class Solution {
  public long maxBalancedSubsequenceSum(int[] nums) {
    // Let's define maxSum[i] := subsequence with the maximum sum ending in i
    // By observation:
    //     nums[i] - nums[j] >= i - j
    //  => nums[i] - i >= nums[j] - j
    //  So, if nums[i] - i >= nums[j] - j, where i > j,
    //  maxSum[i] = max(maxSum[i], maxSum[j] + nums[i])
    long ans = Long.MIN_VALUE;
    FenwickTree tree = new FenwickTree(nums.length);

    for (Pair<Integer, Integer> pair : getPairs(nums)) {
      final int i = pair.getValue();
      final long subseqSum = tree.get(i) + nums[i];
      tree.update(i + 1, subseqSum);
      ans = Math.max(ans, subseqSum);
    }

    return ans;
  }

  private List<Pair<Integer, Integer>> getPairs(int[] nums) {
    List<Pair<Integer, Integer>> pairs = new ArrayList<>();
    for (int i = 0; i < nums.length; ++i)
      pairs.add(new Pair<>(nums[i] - i, i));
    pairs.sort((p1, p2) -> p1.getKey() - p2.getKey());
    return pairs;
  }
}
