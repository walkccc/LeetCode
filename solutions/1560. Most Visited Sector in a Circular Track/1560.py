class Solution:
  def mostVisited(self, n: int, rounds: List[int]) -> List[int]:
    # Case 1: if start <= end, [start, end] is the most visited.
    #
    #      s --------- n
    # 1 -------------- n
    # 1 ------ e
    #
    # Case 2: if start > end, [1, end] and [start, n] are the most visited.
    #
    #             s -- n
    # 1 -------------- n
    # 1 ------ e
    start = rounds[0]
    end = rounds[-1]
    if start <= end:
      return range(start, end + 1)
    return list(range(1, end + 1)) + list(range(start, n + 1))
