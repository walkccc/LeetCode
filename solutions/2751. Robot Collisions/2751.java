class Robot {
  public int index;
  public int position;
  public int health;
  public char direction;
  public Robot(int index, int position, int health, char direction) {
    this.index = index;
    this.position = position;
    this.health = health;
    this.direction = direction;
  }
}

class Solution {
  public List<Integer> survivedRobotsHealths(int[] positions, int[] healths, String directions) {
    List<Integer> ans = new ArrayList<>();
    Robot[] robots = new Robot[positions.length];
    List<Robot> stack = new ArrayList<>(); // running robots

    for (int i = 0; i < positions.length; ++i)
      robots[i] = new Robot(i, positions[i], healths[i], directions.charAt(i));

    Arrays.sort(robots, (a, b) -> Integer.compare(a.position, b.position));

    for (Robot robot : robots) {
      if (robot.direction == 'R') {
        stack.add(robot);
        continue;
      }
      // Collide with robots going right if any.
      while (!stack.isEmpty() && stack.get(stack.size() - 1).direction == 'R' && robot.health > 0) {
        if (stack.get(stack.size() - 1).health == robot.health) {
          stack.remove(stack.size() - 1);
          robot.health = 0;
        } else if (stack.get(stack.size() - 1).health < robot.health) {
          stack.remove(stack.size() - 1);
          robot.health -= 1;
        } else { // stack[-1].health > robot.health
          stack.get(stack.size() - 1).health -= 1;
          robot.health = 0;
        }
      }
      if (robot.health > 0)
        stack.add(robot);
    }

    stack.sort((a, b) -> Integer.compare(a.index, b.index));

    for (Robot robot : stack)
      ans.add(robot.health);

    return ans;
  }
}
