class Solution {
  public long maxSubarrays(int n, int[][] conflictingPairs) {
    long validSubarrays = 0;
    int maxLeft = 0;
    int secondMaxLeft = 0;
    // gains[i] := the number of additional valid subarrays we can gain if the
    // restriction at index `i` is removed
    long[] gains = new long[n + 1];
    // conflicts[r] := left endpoints that conflict with subarrays ending in r
    List<Integer>[] conflicts = new List[n + 1];

    for (int i = 0; i <= n; ++i)
      conflicts[i] = new ArrayList<>();

    for (int[] pair : conflictingPairs) {
      final int a = pair[0];
      final int b = pair[1];
      conflicts[Math.max(a, b)].add(Math.min(a, b));
    }

    for (int right = 1; right <= n; ++right) {
      for (int left : conflicts[right]) {
        if (left > maxLeft) {
          secondMaxLeft = maxLeft;
          maxLeft = left;
        } else if (left > secondMaxLeft) {
          secondMaxLeft = left;
        }
      }
      // Subarrays [maxLeft + 1..right],
      //           [maxLeft + 2..right],
      //           ...
      //           [right..right] are valid.
      validSubarrays += right - maxLeft;
      // If we remove `maxLeft` (the most restrictive conflict), we gain
      // `maxLeft - secondMaxLeft` new subarrays:
      // [secondMaxLeft + 1..right],
      // [secondMaxLeft + 2..right],
      // ...
      // [maxLeft..right].
      gains[maxLeft] += maxLeft - secondMaxLeft;
    }

    return validSubarrays + Arrays.stream(gains).max().getAsLong();
  }
}
