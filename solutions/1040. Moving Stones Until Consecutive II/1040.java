class Solution {
  public int[] numMovesStonesII(int[] stones) {
    final int n = stones.length;
    int minMoves = n;

    Arrays.sort(stones);

    for (int l = 0, r = 0; r < n; ++r) {
      while (stones[r] - stones[l] + 1 > n)
        ++l;
      int alreadyStored = r - l + 1;
      if (alreadyStored == n - 1 && stones[r] - stones[l] + 1 == n - 1)
        minMoves = Math.min(minMoves, 2);
      else
        minMoves = Math.min(minMoves, n - alreadyStored);
    }

    return new int[] {
        minMoves, Math.max(stones[n - 1] - stones[1] - n + 2, stones[n - 2] - stones[0] - n + 2)};
  }
}
