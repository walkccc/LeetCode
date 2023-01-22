class Solution {
  public boolean pyramidTransition(String bottom, List<String> allowed) {
    Map<String, List<Character>> prefixToBlocks = new HashMap<>();

    for (final String a : allowed) {
      final String lowerBlocks = a.substring(0, 2);
      prefixToBlocks.putIfAbsent(lowerBlocks, new LinkedList<>());
      prefixToBlocks.get(lowerBlocks).add(a.charAt(2));
    }

    return dfs(bottom, "", 0, prefixToBlocks);
  }

  private boolean dfs(final String row, final String nextRow, int i,
                      Map<String, List<Character>> prefixToBlocks) {
    if (row.length() == 1)
      return true;
    if (nextRow.length() + 1 == row.length())
      return dfs(nextRow, "", 0, prefixToBlocks);

    final String prefix = row.substring(i, i + 2);

    if (prefixToBlocks.containsKey(prefix))
      for (final char c : prefixToBlocks.get(prefix))
        if (dfs(row, nextRow + c, i + 1, prefixToBlocks))
          return true;

    return false;
  }
}
