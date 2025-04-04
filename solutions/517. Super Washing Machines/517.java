class Solution {
  public int findMinMoves(int[] machines) {
    int dresses = Arrays.stream(machines).sum();
    if (dresses % machines.length != 0)
      return -1;

    int ans = 0;
    int inout = 0;
    final int average = dresses / machines.length;

    for (final int dress : machines) {
      inout += dress - average;
      ans = Math.max(ans, Math.max(Math.abs(inout), dress - average));
    }

    return ans;
  }
}
