class Solution {
  public boolean pyramidTransition(String bottom, List<String> allowed) {
    Map<String, List<Character>> prefixToBlocks = new HashMap<>();

    for (final String a : allowed)
      prefixToBlocks.computeIfAbsent(a.substring(0, 2), k -> new LinkedList<>()).add(a.charAt(2));

    return dfs(bottom, "", prefixToBlocks, 0);
  }

  private boolean dfs(final String row, final String nextRow, Map<String, List<Character>> prefixToBlocks, int i) {
    if (row.length() == 1)
      return true;
    if (nextRow.length() + 1 == row.length())
      return dfs(nextRow, "", prefixToBlocks, 0);

    for (char c : prefixToBlocks.getOrDefault(row.substring(i, i + 2), new LinkedList<>()))
      if (dfs(row, nextRow + c, prefixToBlocks, i + 1))
        return true;

    return false;
  }
}