class Solution {
  public int[] executeInstructions(int n, int[] startPos, String s) {
    final int m = s.length();
    final int uMost = startPos[0] + 1;
    final int dMost = n - startPos[0];
    final int lMost = startPos[1] + 1;
    final int rMost = n - startPos[1];
    Map<Character, Pair<Integer, Integer>> moves = new HashMap<>();
    moves.put('L', new Pair<>(0, -1));
    moves.put('R', new Pair<>(0, 1));
    moves.put('U', new Pair<>(-1, 0));
    moves.put('D', new Pair<>(1, 0));

    int[] ans = new int[m];
    Map<Integer, Integer> reachX = new HashMap<>();
    Map<Integer, Integer> reachY = new HashMap<>();
    reachX.put(0, m);
    reachY.put(0, m);
    int x = 0;
    int y = 0;

    for (int i = m - 1; i >= 0; --i) {
      Pair<Integer, Integer> pair = moves.get(s.charAt(i));
      final int dx = pair.getKey();
      final int dy = pair.getValue();
      x -= dx;
      y -= dy;
      reachX.put(x, i);
      reachY.put(y, i);
      final int out = Math.min(Math.min(reachX.getOrDefault(x - uMost, Integer.MAX_VALUE),
                                        reachX.getOrDefault(x + dMost, Integer.MAX_VALUE)),
                               Math.min(reachY.getOrDefault(y - lMost, Integer.MAX_VALUE),
                                        reachY.getOrDefault(y + rMost, Integer.MAX_VALUE)));
      ans[i] = out == Integer.MAX_VALUE ? m - i : out - i - 1;
    }

    return ans;
  }
}
