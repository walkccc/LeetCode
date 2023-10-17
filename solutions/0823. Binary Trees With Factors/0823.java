class Solution {
  public int numFactoredBinaryTrees(int[] arr) {
    final int kMod = 1_000_000_007;
    final int n = arr.length;
    // dp[i] := # of binary trees with arr[i] as root
    long[] dp = new long[n];
    Map<Integer, Integer> numToIndex = new HashMap<>();

    Arrays.sort(arr);
    Arrays.fill(dp, 1);

    for (int i = 0; i < n; ++i)
      numToIndex.put(arr[i], i);

    for (int i = 0; i < n; ++i) // arr[i] is root
      for (int j = 0; j < i; ++j)
        if (arr[i] % arr[j] == 0) { // arr[j] is left subtree
          final int right = arr[i] / arr[j];
          if (numToIndex.containsKey(right)) {
            dp[i] += dp[j] * dp[numToIndex.get(right)];
            dp[i] %= kMod;
          }
        }

    return (int) (Arrays.stream(dp).sum() % kMod);
  }
}
