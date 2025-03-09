class Solution {
  public int maxCoins(int[] piles) {
    Arrays.sort(piles);

    int ans = 0;

    // piles = [S S M L M L], pick all the M.
    for (int i = piles.length / 3; i < piles.length; i += 2)
      ans += piles[i];

    return ans;
  }
}
