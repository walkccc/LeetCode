class Solution {
  public int findMinStep(String board, String hand) {
    Map<String, Integer> mem = new HashMap<>();
    final int ans = dfs(board + '#', hand, mem);
    return ans == Integer.MAX_VALUE ? -1 : ans;
  }

  private int dfs(String board, final String hand, Map<String, Integer> mem) {
    final String hashKey = board + '#' + hand;
    if (mem.containsKey(hashKey))
      return mem.get(hashKey);
    board = deDup(board);
    if (board.equals("#"))
      return 0;

    Set<Character> boardSet = new HashSet<>();
    for (final char c : board.toCharArray())
      boardSet.add(c);

    StringBuilder sb = new StringBuilder();
    for (final char h : hand.toCharArray())
      if (boardSet.contains(h))
        sb.append(h);
    final String hs = sb.toString();
    if (sb.length() == 0) // infeasible
      return Integer.MAX_VALUE;

    int ans = Integer.MAX_VALUE;

    for (int i = 0; i < board.length(); ++i)
      for (int j = 0; j < hs.length(); ++j) {
        // Place hs[j] in board[i].
        final String newHand = hs.substring(0, j) + hs.substring(j + 1);
        String newBoard = board.substring(0, i) + hs.charAt(j) + board.substring(i);
        final int res = dfs(newBoard, newHand, mem);
        if (res < Integer.MAX_VALUE)
          ans = Math.min(ans, 1 + res);
      }

    mem.put(hashKey, ans);
    return ans;
  }

  private String deDup(String board) {
    int start = 0; // the start index of a color sequenece
    for (int i = 0; i < board.length(); ++i)
      if (board.charAt(i) != board.charAt(start)) {
        if (i - start >= 3)
          return deDup(board.substring(0, start) + board.substring(i));
        start = i; // Meet a new sequence.
      }
    return board;
  }
}
