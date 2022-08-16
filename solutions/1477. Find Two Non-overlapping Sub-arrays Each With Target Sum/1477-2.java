class Solution {
  public int minSumOfLengths(int[] arr, int target) {
    int ans = Integer.MAX_VALUE;
    int sum = 0; // window sum
    // best[i] := min length of subarray of arr[0..i] that has sum = target
    int[] best = new int[arr.length];
    Arrays.fill(best, Integer.MAX_VALUE);

    for (int l = 0, r = 0; r < arr.length; ++r) {
      sum += arr[r]; // expand window
      while (sum > target)
        sum -= arr[l++]; // shrink window
      if (sum == target) {
        if (l > 0 && best[l - 1] != Integer.MAX_VALUE)
          ans = Math.min(ans, best[l - 1] + r - l + 1);
        best[r] = Math.min(best[r], r - l + 1);
      }
      if (r > 0)
        best[r] = Math.min(best[r], best[r - 1]);
    }

    return ans == Integer.MAX_VALUE ? -1 : ans;
  }
}
