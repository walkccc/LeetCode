class Solution:
  def getCollisionTimes(self, cars: List[List[int]]) -> List[float]:
    ans = []
    stack = []  # (pos, speed, collisionTime)

    def getCollisionTime(
            car: Tuple[int, int, int],
            pos: int, speed: int) -> float:
      return (car[0] - pos) / (speed - car[1])

    for pos, speed in reversed(cars):
      while stack and (
              speed <= stack[-1][1] or getCollisionTime(stack[-1],
                                                        pos, speed) >=
              stack[-1][2]):
        stack.pop()
      if stack:
        collisionTime = getCollisionTime(stack[-1], pos, speed)
        stack.append((pos, speed, collisionTime))
        ans.append(collisionTime)
      else:
        stack.append((pos, speed, math.inf))
        ans.append(-1)

    return ans[::-1]
