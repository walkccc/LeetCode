class Solution:
  def minGroupsForValidAssignment(self, nums: List[int]) -> int:
    count = collections.Counter(nums)
    minFreq = min(count.values())

    for groupSize in range(minFreq, 0, -1):
      numGroups = self.getNumGroups(count, groupSize)
      if numGroups > 0:
        return numGroups

    raise ValueError("Invalid argument")

  def getNumGroups(self, count: Dict[int, int], groupSize: int) -> int:
    """Returns the number of groups if each group's size is `groupSize` or `groupSize + 1`."""
    numGroups = 0
    for freq in count.values():
      a = freq // (groupSize + 1)
      b = freq % (groupSize + 1)
      if b == 0:
        # Assign 1 number from `groupSize - b` out of `a` groups to this group,
        # so we'll have `a - (groupSize - b)` groups of size `groupSize + 1`
        # and `groupSize - b + 1` groups of size `groupSize`. In total, we have
        # `a + 1` groups.
        numGroups += a
      elif groupSize - b <= a:
        numGroups += a + 1
      else:
        return 0
    return numGroups
