class Solution:
  def leastBricks(self, wall: List[List[int]]) -> int:
    maxFreq = 0
    count = collections.defaultdict(int)

    for row in wall:
      prefix = 0
      for i in range(len(row) - 1):
        prefix += row[i]
        count[prefix] += 1
        maxFreq = max(maxFreq, count[prefix])

    return len(wall) - maxFreq
