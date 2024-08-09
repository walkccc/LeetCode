class Solution:
  def largestTimeFromDigits(self, arr: List[int]) -> str:
    for time in itertools.permutations(sorted(arr, reverse=True)):
      if time[:2] < (2, 4) and time[2] < 6:
        return '%d%d:%d%d' % time
    return ''
