class Solution {
  public boolean canVisitAllRooms(List<List<Integer>> rooms) {
    int[] seen = new int[rooms.size()];
    dfs(rooms, 0, seen);
    return Arrays.stream(seen).allMatch(a -> a == 1);
  }

  private void dfs(List<List<Integer>> rooms, int node, int[] seen) {
    seen[node] = 1;
    for (final int child : rooms.get(node))
      if (seen[child] == 0)
        dfs(rooms, child, seen);
  }
}
