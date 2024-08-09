class Solution:
  def averageHeightOfBuildings(self, buildings: List[List[int]]) -> List[List[int]]:
    ans = []
    events = []

    for start, end, height in buildings:
      events.append((start, height))
      events.append((end, -height))

    prev = 0
    count = 0
    sumHeight = 0

    for curr, h in sorted(events):
      height = abs(h)
      if sumHeight > 0 and curr > prev:
        avgHeight = sumHeight // count
        if ans and ans[-1][1] == prev and avgHeight == ans[-1][2]:
          ans[-1][1] = curr
        else:
          ans.append([prev, curr, avgHeight])
      sumHeight += h
      count += 1 if h > 0 else -1
      prev = curr

    return ans
