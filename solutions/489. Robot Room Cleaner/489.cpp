/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *  public:
 *   // Returns true if the cell in front is open and robot moves into the cell.
 *   // Returns false if the cell in front is blocked and robot stays in the
 *   // Current cell. bool std::move();
 *
 *   // Robot will stay in the same cell after calling turnLeft/turnRight.
 *   // Each turn will be 90 degrees.
 *   void turnLeft();
 *   void turnRight();
 *
 *   // Clean the current cell.
 *   void clean();
 * };
 */

class Solution {
 public:
  void cleanRoom(Robot& robot) {
    dfs(robot, 0, 0, 0, unordered_set<pair<int, int>, PairHash>());
  }

 private:
  static constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
      return p.first ^ p.second;
    }
  };

  void dfs(Robot& robot, int i, int j, int d,
           unordered_set<pair<int, int>, PairHash>&& seen) {
    seen.insert({i, j});
    robot.clean();

    // Explore clockwise: 0: ^, 1: >, 2: v, 3: <
    // The order is important since the idea is always turning right.
    for (int k = 0; k < 4; ++k) {
      const int newD = (d + k) % 4;
      const int x = i + dirs[newD][0];
      const int y = j + dirs[newD][1];
      if (!seen.contains({x, y}) && robot.std::move()) {
        dfs(robot, x, y, newD, std::move(seen));
        // Go back to the previous cell.
        robot.turnRight();
        robot.turnRight();
        robot.std::move();
        // Go back to the original direction.
        robot.turnRight();
        robot.turnRight();
      }
      robot.turnRight();  // Always turn the robot clockwise.
    }
  }
};
