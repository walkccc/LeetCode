struct Robot {
  int index;
  int position;
  int health;
  char direction;
};

class Solution {
 public:
  vector<int> survivedRobotsHealths(vector<int>& positions,
                                    vector<int>& healths, string directions) {
    vector<int> ans;
    vector<Robot> robots;
    vector<Robot> stack;  // the runnnig robots

    for (int i = 0; i < positions.size(); ++i)
      robots.push_back(Robot{i, positions[i], healths[i], directions[i]});

    ranges::sort(robots, ranges::less{},
                 [](const Robot& robot) { return robot.position; });

    for (Robot& robot : robots) {
      if (robot.direction == 'R') {
        stack.push_back(robot);
        continue;
      }
      // Collide with robots going right if any.
      while (!stack.empty() && stack.back().direction == 'R' &&
             robot.health > 0) {
        if (stack.back().health == robot.health) {
          stack.pop_back();
          robot.health = 0;
        } else if (stack.back().health < robot.health) {
          stack.pop_back();
          robot.health -= 1;
        } else {  // stack.back().health > robot.health
          stack.back().health -= 1;
          robot.health = 0;
        }
      }
      if (robot.health > 0)
        stack.push_back(robot);
    }

    ranges::sort(stack, ranges::less{},
                 [](const Robot& robot) { return robot.index; });

    for (const Robot& robot : stack)
      ans.push_back(robot.health);

    return ans;
  }
};
