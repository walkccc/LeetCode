class Solution {
  public int waysToSplit(int[] nums) {
    final int kMod = 1_000_000_007;
    final int n = nums.length;
    int ans = 0;
    int[] prefix = nums.clone();

    for (int i = 1; i < n; ++i)
      prefix[i] += prefix[i - 1];

    for (int i = 0, j = 0, k = 0; i < n - 2; ++i) {
      // Find the first index j s.t.
      // left = prefix[i] <= mid = prefix[j] - prefix[i]
      j = Math.max(j, i + 1);
      while (j < n - 1 && prefix[i] > prefix[j] - prefix[i])
        ++j;
      // Find the first index k s.t.
      // mid = prefix[k] - prefix[i] > right = prefix[-1] - prefix[k]
      k = Math.max(k, j);
      while (k < n - 1 && prefix[k] - prefix[i] <= prefix[prefix.length - 1] - prefix[k])
        ++k;
      ans += k - j;
      ans %= kMod;
    }

    return ans;
  }
}
