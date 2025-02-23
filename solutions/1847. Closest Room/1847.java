class Solution {
  public int[] closestRoom(int[][] rooms, int[][] queries) {
    int[] ans = new int[queries.length];
    Integer[] indices = new Integer[queries.length];
    TreeSet<Integer> roomIds = new TreeSet<>();

    for (int i = 0; i < queries.length; ++i)
      indices[i] = i;

    Arrays.sort(rooms, (a, b) -> Integer.compare(b[1], a[1]));
    Arrays.sort(indices, (a, b) -> Integer.compare(queries[b][1], queries[a][1]));

    int i = 0; // rooms' index
    for (final int index : indices) {
      while (i < rooms.length && rooms[i][1] >= queries[index][1])
        roomIds.add(rooms[i++][0]);
      ans[index] = searchClosestRoomId(roomIds, queries[index][0]);
    }

    return ans;
  }

  private int searchClosestRoomId(TreeSet<Integer> roomIds, int preferred) {
    Integer floor = roomIds.floor(preferred);
    Integer ceiling = roomIds.ceiling(preferred);
    final int id1 = floor == null ? -1 : floor;
    final int id2 = ceiling == null ? -1 : ceiling;
    if (id1 == -1)
      return id2;
    if (id2 == -1)
      return id1;
    if (Math.abs(preferred - id1) <= Math.abs(preferred - id2))
      return id1;
    return id2;
  }
}
