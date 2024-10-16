class Solution {
  public int robotSim(int[] commands, int[][] obstacles) {
    final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int ans = 0;
    int d = 0; // 0 := north, 1 := east, 2 := south, 3 := west
    int x = 0; // the start x
    int y = 0; // the start y
    Set<Pair<Integer, Integer>> obstaclesSet = new HashSet<>();

    for (int[] obstacle : obstacles) {
      final int x_ = obstacle[0];
      final int y_ = obstacle[1];
      obstaclesSet.add(new Pair<>(x_, y_));
    }

    for (final int command : commands) {
      if (command == -1) {
        d = (d + 1) % 4;
      } else if (command == -2) {
        d = (d + 3) % 4;
      } else {
        for (int step = 0; step < command; ++step) {
          if (obstaclesSet.contains(new Pair<>(x + dirs[d][0], y + dirs[d][1])))
            break;
          x += dirs[d][0];
          y += dirs[d][1];
        }
      }
      ans = Math.max(ans, x * x + y * y);
    }

    return ans;
  }
}
