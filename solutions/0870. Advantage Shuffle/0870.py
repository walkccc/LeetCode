from sortedcontainers import SortedList


class Solution:
  def advantageCount(self, A: List[int], B: List[int]) -> List[int]:
    sl = SortedList(A)

    for i, b in enumerate(B):
      index = 0 if sl[-1] <= b else sl.bisect_right(b)
      A[i] = sl[index]
      del sl[index]

    return A
