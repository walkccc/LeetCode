class Solution {
  public long maxGcdSum(int[] nums, int k) {
    long ans = 0;
    // [(startIndex, gcd of subarray starting at startIndex)]
    List<Pair<Integer, Integer>> startIndexAndGcds = new ArrayList<>();
    long[] prefix = new long[nums.length + 1];

    for (int i = 0; i < nums.length; ++i)
      prefix[i + 1] = (long) nums[i] + prefix[i];

    for (int i = 0; i < nums.length; ++i) {
      List<Pair<Integer, Integer>> nextStartIndexAndGcds = new ArrayList<>();
      for (Pair<Integer, Integer> pair : startIndexAndGcds) {
        final int startIndex = pair.getKey();
        final int gcd = pair.getValue();
        final int nextGcd = gcd(gcd, nums[i]);
        if (nextStartIndexAndGcds.isEmpty() ||
            !nextStartIndexAndGcds.get(nextStartIndexAndGcds.size() - 1)
                 .getValue()
                 .equals(nextGcd)) // Skip duplicates.
          nextStartIndexAndGcds.add(new Pair<>(startIndex, nextGcd));
      }
      startIndexAndGcds = new ArrayList<>(nextStartIndexAndGcds);
      startIndexAndGcds.add(new Pair<>(i, nums[i]));
      for (Pair<Integer, Integer> pair : startIndexAndGcds) {
        final int startIndex = pair.getKey();
        final int gcd = pair.getValue();
        if (i - startIndex + 1 >= k)
          ans = Math.max(ans, (prefix[i + 1] - prefix[startIndex]) * gcd);
      }
    }

    return ans;
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}
