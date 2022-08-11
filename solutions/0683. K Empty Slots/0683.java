class Solution {
  public int kEmptySlots(int[] bulbs, int k) {
    final int n = bulbs.length;
    int ans = Integer.MAX_VALUE;
    // day[i] := the day when bulbs[i] is turned on
    int[] day = new int[n];

    for (int i = 0; i < n; ++i)
      day[bulbs[i] - 1] = i + 1;

    // find a subarray of day[l..r], where its length is k + 2
    // for all that l < i < r, day[i] > max(day[l], day[r])
    int l = 0;
    int r = l + k + 1;
    for (int i = 1; r < n; ++i)
      if (i == r) {
        ans = Math.min(ans, Math.max(day[l], day[r]));
        l = i;
        r = i + k + 1;
      } else if (day[i] < Math.max(day[l], day[r])) {
        l = i;
        r = i + k + 1;
      }

    return ans == Integer.MAX_VALUE ? -1 : ans;
  }
}
