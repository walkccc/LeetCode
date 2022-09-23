enum State { DRAW, MOUSE_WIN, CAT_WIN }

class Solution {
  public int catMouseGame(int[][] graph) {
    final int n = graph.length;
    // result of (cat, mouse, move)
    // move := 0 (mouse) / 1 (cat)
    int[][][] states = new int[n][n][2];
    int[][][] outDegree = new int[n][n][2];
    Queue<int[]> q = new ArrayDeque<>();

    for (int cat = 0; cat < n; ++cat)
      for (int mouse = 0; mouse < n; ++mouse) {
        outDegree[cat][mouse][0] = graph[mouse].length;
        outDegree[cat][mouse][1] =
            graph[cat].length - (Arrays.stream(graph[cat]).anyMatch(v -> v == 0) ? 1 : 0);
      }

    // start from states that winner can be determined
    for (int cat = 1; cat < n; ++cat)
      for (int move = 0; move < 2; ++move) {
        // mouse is in the hole -> MOUSE WIN
        states[cat][0][move] = State.MOUSE_WIN.ordinal();
        q.offer(new int[] {cat, 0, move, State.MOUSE_WIN.ordinal()});
        // cat catches mouse -> CAT_WIN
        states[cat][cat][move] = State.CAT_WIN.ordinal();
        q.offer(new int[] {cat, cat, move, State.CAT_WIN.ordinal()});
      }

    while (!q.isEmpty()) {
      final int cat = q.peek()[0];
      final int mouse = q.peek()[1];
      final int move = q.peek()[2];
      final int state = q.poll()[3];
      if (cat == 2 && mouse == 1 && move == 0)
        return state;
      final int prevMove = move ^ 1;
      for (final int prev : graph[prevMove == 0 ? mouse : cat]) {
        final int prevCat = prevMove == 0 ? cat : prev;
        if (prevCat == 0) // invalid
          continue;
        final int prevMouse = prevMove == 0 ? prev : mouse;
        // the state is already determined
        if (states[prevCat][prevMouse][prevMove] > 0)
          continue;
        if (prevMove == 0 && state == State.MOUSE_WIN.ordinal() ||
            prevMove == 1 && state == State.CAT_WIN.ordinal() ||
            --outDegree[prevCat][prevMouse][prevMove] == 0) {
          states[prevCat][prevMouse][prevMove] = state;
          q.offer(new int[] {prevCat, prevMouse, prevMove, state});
        }
      }
    }

    return states[2][1][0];
  }
}
