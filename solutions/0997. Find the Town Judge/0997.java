class Solution {
  public int findJudge(int n, int[][] trust) {
    int[] count = new int[n + 1];

    for (int[] t : trust) {
      --count[t[0]];
      ++count[t[1]];
    }

    for (int i = 1; i < n + 1; ++i)
      if (count[i] == n - 1)
        return i;

    return -1;
  }
}
