class Solution:
  def minAvailableDuration(self, slots1: List[List[int]], slots2: List[List[int]], duration: int) -> List[int]:
    slots1.sort()
    slots2.sort()

    i = 0  # slots1's index
    j = 0  # slots2's index

    while i < len(slots1) and j < len(slots2):
      start = max(slots1[i][0], slots2[j][0])
      end = min(slots1[i][1], slots2[j][1])
      if start + duration <= end:
        return [start, start + duration]
      if slots1[i][1] < slots2[j][1]:
        i += 1
      else:
        j += 1

    return []
