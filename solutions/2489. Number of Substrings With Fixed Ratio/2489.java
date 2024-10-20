class Solution {
  public long fixedRatio(String s, int num1, int num2) {
    // Let x := the number of 0s and y := the number of 1s in the subarray.
    // We want x : y = num1 : num2, so our goal is to find number of subarrays
    // with x * num2 - y * num1 = 0. To achieve this, we can use a prefix count
    // map to record the count of the running x * num2 - y * num1. If the
    // running x * num2 - y * num1 = prefix, then add count[prefix] to the
    // `ans`.
    long ans = 0;
    long prefix = 0;
    Map<Long, Integer> prefixCount = new HashMap<>();
    prefixCount.put(0L, 1);

    for (final char c : s.toCharArray()) {
      if (c == '0')
        prefix += num2;
      else // c == '1'
        prefix -= num1;
      ans += prefixCount.getOrDefault(prefix, 0);
      prefixCount.merge(prefix, 1, Integer::sum);
    }

    return ans;
  }
}
