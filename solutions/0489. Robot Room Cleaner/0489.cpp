/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *  public:
 *   // Returns true if the cell in front is open and robot moves into the cell.
 *   // Returns false if the cell in front is blocked and robot stays in the
 *   // current cell. bool move();
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
    dfs(robot, 0, 0, 0, unordered_set<pair<int, int>, pairHash>());
  }

 private:
  const vector<int> dirs{0, 1, 0, -1, 0};

  struct pairHash {
    size_t operator()(const pair<int, int>& p) const {
      return p.first ^ p.second;
    }
  };

  void dfs(Robot& robot, int i, int j, int d,
           unordered_set<pair<int, int>, pairHash>&& seen) {
    seen.insert({i, j});
    robot.clean();

    // explore clockwise: 0: ^, 1: >, 2: v, 3: <
    // the order is important since the idea is always turn right
    for (int k = 0; k < 4; ++k) {
      const int newD = (d + k) % 4;
      const int x = i + dirs[newD];
      const int y = j + dirs[newD + 1];
      if (!seen.count({x, y}) && robot.move()) {
        dfs(robot, x, y, newD, move(seen));
        // go back to the previous cell
        robot.turnRight();
        robot.turnRight();
        robot.move();
        // go back to the original direction
        robot.turnRight();
        robot.turnRight();
      }
      robot.turnRight();  // always turn the robot clockwise
    }
  }
};
