class Solution {
  public int maxDistToClosest(int[] seats) {
    final int n = seats.length;
    int ans = 0;
    int j = -1;

    for (int i = 0; i < n; ++i)
      if (seats[i] == 1) {
        ans = j == -1 ? i : Math.max(ans, (i - j) / 2);
        j = i;
      }

    return Math.max(ans, n - j - 1);
  }
}
