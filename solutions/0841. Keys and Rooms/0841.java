class Solution {
  public boolean canVisitAllRooms(List<List<Integer>> rooms) {
    boolean[] seen = new boolean[rooms.size()];

    dfs(rooms, 0, seen);

    for (final boolean s : seen)
      if (!s)
        return false;

    return true;
  }

  private void dfs(List<List<Integer>> rooms, int node, boolean[] seen) {
    seen[node] = true;

    for (final int child : rooms.get(node))
      if (!seen[child])
        dfs(rooms, child, seen);
  }
}
