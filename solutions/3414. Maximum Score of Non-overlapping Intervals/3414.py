from dataclasses import dataclass


@dataclass(frozen=True)
class T:
  weight: int
  selected: tuple[int]

  def __iter__(self):
    yield self.weight
    yield self.selected


class Solution:
  def maximumWeight(self, intervals: list[list[int]]) -> list[int]:
    intervals = sorted((*interval, i) for i, interval in enumerate(intervals))

    @functools.lru_cache(None)
    def dp(i: int, quota: int) -> T:
      """
      Returns the maximum weight and the selected intervals for intervals[i..n),
      where `quota` is the number of intervals that can be selected.
      """
      if i == len(intervals) or quota == 0:
        return T(0, ())

      skip = dp(i + 1, quota)

      _, r, weight, originalIndex = intervals[i]
      j = bisect.bisect_right(intervals, (r, math.inf))
      nextRes = dp(j, quota - 1)
      pick = T(weight + nextRes.weight,
               sorted((originalIndex, *nextRes.selected)))
      return (pick if (pick.weight > skip.weight or
                       pick.weight == skip.weight and pick.selected < skip.selected)
              else skip)

    return list(dp(0, 4).selected)
