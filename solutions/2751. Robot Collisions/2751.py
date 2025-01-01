from dataclasses import dataclass


@dataclass
class Robot:
  index: int
  position: int
  health: int
  direction: str


class Solution:
  def survivedRobotsHealths(
      self,
      positions: list[int],
      healths: list[int],
      directions: str,
  ) -> list[int]:
    robots = sorted([Robot(index, position, health, direction)
                     for index, (position, health, direction) in
                     enumerate(zip(positions, healths, directions))],
                    key=lambda x: x.position)
    stack: list[Robot] = []  # running robots

    for robot in robots:
      if robot.direction == 'R':
        stack.append(robot)
        continue
      # Collide with robots going right if any.
      while stack and stack[-1].direction == 'R' and robot.health > 0:
        if stack[-1].health == robot.health:
          stack.pop()
          robot.health = 0
        elif stack[-1].health < robot.health:
          stack.pop()
          robot.health -= 1
        else:  # stack[-1].health > robot.health
          stack[-1].health -= 1
          robot.health = 0
      if robot.health > 0:
        stack.append(robot)

    stack.sort(key=lambda robot: robot.index)
    return [robot.health for robot in stack]
