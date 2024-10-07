/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * interface Robot {
 *   // Returns true if the cell in front is open and robot moves into the cell.
 *   // Returns false if the cell in front is blocked and robot stays in the current cell.
 *   public boolean move();
 *
 *   // Robot will stay in the same cell after calling turnLeft/turnRight.
 *   // Each turn will be 90 degrees.
 *   public void turnLeft();
 *   public void turnRight();
 *
 *   // Clean the current cell.
 *   public void clean();
 * }
 */

class Solution {
  public void cleanRoom(Robot robot) {
    dfs(robot, 0, 0, 0, new HashSet<>());
  }

  private static final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  private void dfs(Robot robot, int d, int i, int j, Set<Pair<Integer, Integer>> seen) {
    seen.add(new Pair<>(i, j));
    robot.clean();

    // Explore clockwise: 0: ^, 1: >, 2: v, 3: <
    // The order is important since the idea is always turning right.
    for (int k = 0; k < 4; ++k) {
      final int newD = (d + k) % 4;
      final int x = i + dirs[newD][0];
      final int y = j + dirs[newD][1];
      if (!seen.contains(new Pair<>(x, y)) && robot.move()) {
        dfs(robot, newD, x, y, seen);
        // Go back to the previous cell.
        robot.turnRight();
        robot.turnRight();
        robot.move();
        // Go back to the original direction.
        robot.turnRight();
        robot.turnRight();
      }
      robot.turnRight(); // Always turn the robot clockwise.
    }
  }
}
