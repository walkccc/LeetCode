class Solution {
  public int minKnightMoves(int x, int y) {
    return dp(Math.abs(x), Math.abs(y));
  }

  private Map<Pair<Integer, Integer>, Integer> memo = new HashMap<>();

  private int dp(int x, int y) {
    if (x + y == 0) // (0, 0)
      return 0;
    if (x + y == 2) // (0, 2), (1, 1), (2, 0)
      return 2;
    Pair<Integer, Integer> key = new Pair<>(x, y);
    if (memo.containsKey(key))
      return memo.get(key);

    final int minMove = 1 + Math.min(                                 //
                                dp(Math.abs(x - 2), Math.abs(y - 1)), //
                                dp(Math.abs(x - 1), Math.abs(y - 2)));
    memo.put(key, minMove);
    return minMove;
  }
}
