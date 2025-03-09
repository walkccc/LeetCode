class Solution {
  public boolean splitArray(int[] nums) {
    final int n = nums.length;
    if (n < 7)
      return false;

    int[] prefix = new int[n];

    for (int i = 0; i < n; ++i)
      prefix[i] = i == 0 ? nums[0] : prefix[i - 1] + nums[i];

    for (int j = 3; j < n - 3; ++j) {
      HashSet<Integer> seen = new HashSet<>();
      for (int i = 1; i < j - 1; ++i)
        if (prefix[i - 1] == prefix[j - 1] - prefix[i])
          seen.add(prefix[i - 1]);
      for (int k = j + 2; k < n - 1; ++k)
        if (prefix[n - 1] - prefix[k] == prefix[k - 1] - prefix[j] &&
            seen.contains(prefix[k - 1] - prefix[j]))
          return true;
    }

    return false;
  }
}
