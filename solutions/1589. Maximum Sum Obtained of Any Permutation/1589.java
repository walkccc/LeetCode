class Solution {
  public int maxSumRangeQuery(int[] nums, int[][] requests) {
    final int kMod = 1_000_000_007;
    long ans = 0;
    // count[i] := the number of times nums[i] has been requested
    int[] count = new int[nums.length];

    for (int[] request : requests) {
      final int start = request[0];
      final int end = request[1];
      ++count[start];
      if (end + 1 < nums.length)
        --count[end + 1];
    }

    for (int i = 1; i < nums.length; ++i)
      count[i] += count[i - 1];

    Arrays.sort(count);
    Arrays.sort(nums);

    for (int i = 0; i < nums.length; ++i) {
      ans += (long) nums[i] * count[i];
      ans %= kMod;
    }

    return (int) ans;
  }
}
