class Solution {
  public int minTimeToReach(int[][] moveTime) {
    return dijkstra(moveTime, new Pair<>(0, 0),
                    new Pair<>(moveTime.length - 1, moveTime[0].length - 1));
  }

  private int dijkstra(int[][] moveTime, Pair<Integer, Integer> src, Pair<Integer, Integer> dst) {
    final int[][] DIRS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    final int m = moveTime.length;
    final int n = moveTime[0].length;
    int[][] dist = new int[m][n];
    Arrays.stream(dist).forEach(A -> Arrays.fill(A, Integer.MAX_VALUE));

    dist[0][0] = 0;
    Queue<Pair<Integer, Pair<Integer, Integer>>> minHeap =
        new PriorityQueue<>(Comparator.comparingInt(Pair::getKey)) {
          { offer(new Pair<>(dist[0][0], src)); } // (d, u)
        };

    while (!minHeap.isEmpty()) {
      final int d = minHeap.peek().getKey();
      final Pair<Integer, Integer> u = minHeap.poll().getValue();
      if (u.equals(dst))
        return d;
      final int i = u.getKey();
      final int j = u.getValue();
      if (d > dist[i][j])
        continue;
      for (int[] dir : DIRS) {
        final int x = i + dir[0];
        final int y = j + dir[1];
        if (x < 0 || x == m || y < 0 || y == n)
          continue;
        final int newDist = Math.max(moveTime[x][y], d) + 1;
        if (newDist < dist[x][y]) {
          dist[x][y] = newDist;
          minHeap.offer(new Pair<>(newDist, new Pair<>(x, y)));
        }
      }
    }

    return -1;
  }
}
