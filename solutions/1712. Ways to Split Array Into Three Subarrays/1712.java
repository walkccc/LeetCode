class Solution {
  public int waysToSplit(int[] nums) {
    final int kMod = 1_000_000_007;
    final int n = nums.length;
    int ans = 0;
    int[] prefix = nums.clone();

    for (int i = 1; i < n; ++i)
      prefix[i] += prefix[i - 1];

    for (int i = 0; i < n - 2; ++i) {
      final int j = firstGreaterEqual(prefix, i);
      if (j == n - 1)
        break;
      final int mid = prefix[j] - prefix[i];
      final int right = prefix[prefix.length - 1] - prefix[j];
      if (mid > right)
        continue;
      final int k = firstGreater(prefix, i);
      ans = (ans + k - j) % kMod;
    }

    return ans;
  }

  // Finds the first index j s.t.
  // mid = prefix[j] - prefix[i] >= left = prefix[i].
  private int firstGreaterEqual(int[] prefix, int i) {
    int l = i + 1;
    int r = prefix.length - 1;
    while (l < r) {
      final int m = (l + r) / 2;
      if (prefix[m] - prefix[i] >= prefix[i])
        r = m;
      else
        l = m + 1;
    }
    return l;
  };

  // Finds the first index k s.t.
  // mid = prefix[k] - prefix[i] > right = prefix[-1] - prefix[k].
  private int firstGreater(int[] prefix, int i) {
    int l = i + 1;
    int r = prefix.length - 1;
    while (l < r) {
      final int m = (l + r) / 2;
      if (prefix[m] - prefix[i] > prefix[prefix.length - 1] - prefix[m])
        r = m;
      else
        l = m + 1;
    }
    return l;
  };
}
