from sortedcontainers import SortedSet


class Solution:
  def avoidFlood(self, rains: List[int]) -> List[int]:
    ans = [-1] * len(rains)
    lakeIdToFullDay = {}
    emptyDays = SortedSet()  # indices of rains[i] == 0

    for i, lakeId in enumerate(rains):
      if lakeId == 0:
        emptyDays.add(i)
        continue
        # The lake was full in a previous day. Greedily find the closest day
        # to make the lake empty.
      if lakeId in lakeIdToFullDay:
        fullDay = lakeIdToFullDay[lakeId]
        emptyDayIndex = emptyDays.bisect_right(fullDay)
        if emptyDayIndex == len(emptyDays):  # Not found.
          return []
        # Empty the lake at this day.
        emptyDay = emptyDays[emptyDayIndex]
        ans[emptyDay] = lakeId
        emptyDays.discard(emptyDay)
      # The lake with `lakeId` becomes full at the day `i`.
      lakeIdToFullDay[lakeId] = i

    # Empty an arbitrary lake if there are remaining empty days.
    for emptyDay in emptyDays:
      ans[emptyDay] = 1

    return ans
