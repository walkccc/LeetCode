class Solution:
  def averageHeightOfBuildings(self, buildings: list[list[int]]) -> list[list[int]]:
    ans = []
    events = []

    for start, end, height in buildings:
      events.append((start, height))
      events.append((end, -height))

    prev = 0
    count = 0
    sumHeight = 0

    for curr, height in sorted(events):
      if sumHeight > 0 and curr > prev:
        avgHeight = sumHeight // count
        if ans and ans[-1][1] == prev and avgHeight == ans[-1][2]:
          ans[-1][1] = curr
        else:
          ans.append([prev, curr, avgHeight])
      sumHeight += height
      count += 1 if height > 0 else -1
      prev = curr

    return ans
