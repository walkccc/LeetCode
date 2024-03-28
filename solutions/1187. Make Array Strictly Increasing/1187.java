class Solution {
  public int makeArrayIncreasing(int[] arr1, int[] arr2) {
    // dp[i] := the minimum steps to reach i at previous round
    Map<Integer, Integer> dp = new HashMap<>();
    dp.put(-1, 0);

    Arrays.sort(arr2);

    for (final int a : arr1) {
      Map<Integer, Integer> nextDp = new HashMap<>();
      for (final int val : dp.keySet()) {
        final int steps = dp.get(val);
        // It's possible to use the value in the arr1.
        if (a > val)
          nextDp.put(a, Math.min(nextDp.getOrDefault(a, Integer.MAX_VALUE), steps));
        // Also try the value in the arr2.
        final int i = firstGreater(arr2, val);
        if (i < arr2.length)
          nextDp.put(arr2[i], Math.min(nextDp.getOrDefault(arr2[i], Integer.MAX_VALUE), steps + 1));
      }
      if (nextDp.isEmpty())
        return -1;
      dp = nextDp;
    }

    return Collections.min(dp.values());
  }

  private int firstGreater(int[] A, int target) {
    final int i = Arrays.binarySearch(A, target + 1);
    return i < 0 ? -i - 1 : i;
  }
}
