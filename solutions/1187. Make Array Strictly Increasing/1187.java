class Solution {
  public int makeArrayIncreasing(int[] arr1, int[] arr2) {
    // dp[i] := the minimum steps to reach i at previous round
    Map<Integer, Integer> dp = new HashMap<>();
    dp.put(-1, 0);

    Arrays.sort(arr2);

    for (final int a : arr1) {
      Map<Integer, Integer> newDp = new HashMap<>();
      for (final int val : dp.keySet()) {
        final int steps = dp.get(val);
        // It's possible to use the value in the arr1.
        if (a > val)
          newDp.put(a, Math.min(newDp.getOrDefault(a, Integer.MAX_VALUE), steps));
        // Also try the value in the arr2.
        final int i = firstGreater(arr2, val);
        if (i < arr2.length)
          newDp.put(arr2[i], Math.min(newDp.getOrDefault(arr2[i], Integer.MAX_VALUE), steps + 1));
      }
      if (newDp.isEmpty())
        return -1;
      dp = newDp;
    }

    return Collections.min(dp.values());
  }

  private int firstGreater(int[] arr, int target) {
    final int i = Arrays.binarySearch(arr, target + 1);
    return i < 0 ? -i - 1 : i;
  }
}
