class Solution:
  def countDays(self, days: int, meetings: list[list[int]]) -> int:
    freeDays = 0
    prevEnd = 0

    for start, end in sorted(meetings):
      if start > prevEnd:
        freeDays += start - prevEnd - 1
      prevEnd = max(prevEnd, end)

    return freeDays + max(0, days - prevEnd)
