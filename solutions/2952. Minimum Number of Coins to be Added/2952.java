class Solution {
  // Same as 330. Patching Array
  public int minimumAddedCoins(int[] coins, int target) {
    int ans = 0;
    int i = 0;     // coins' index
    long miss = 1; // the minimum sum in [1, n] we might miss

    Arrays.sort(coins);

    while (miss <= target)
      if (i < coins.length && coins[i] <= miss) {
        miss += coins[i++];
      } else {
        // Greedily add `miss` itself to increase the range from
        // [1, miss) to [1, 2 * miss).
        miss += miss;
        ++ans;
      }

    return ans;
  }
}
