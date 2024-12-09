from sortedcontainers import SortedDict


class Solution:
  def maxArea(self, height: int, positions: list[int], directions: str) -> int:
    area = sum(positions)
    ans = area
    diffPerSecond = 0
    timeToIndices: SortedDict[int, list[int]] = SortedDict()

    for i, (position, direction) in enumerate(zip(positions, directions)):
      if direction == 'U':
        timeToIndices.setdefault(height - position, []).append(i)
        timeToIndices.setdefault(height - position + height, []).append(i)
        diffPerSecond += 1
      else:
        timeToIndices.setdefault(position, []).append(i)
        timeToIndices.setdefault(position + height, []).append(i)
        diffPerSecond -= 1

    prevTime = 0
    directionsList = list(directions)

    for time, indices in timeToIndices.items():
      area += (time - prevTime) * diffPerSecond
      ans = max(ans, area)
      prevTime = time
      for i in indices:
        if directionsList[i] == 'U':
          directionsList[i] = 'D'
          diffPerSecond -= 2
        else:
          directionsList[i] = 'U'
          diffPerSecond += 2

    return ans
