class Solution:
  def largestTimeFromDigits(self, A: List[int]) -> str:
    for time in itertools.permutations(sorted(A, reverse=True)):
      if time[:2] < (2, 4) and time[2] < 6:
        return '%d%d:%d%d' % time

    return ''
