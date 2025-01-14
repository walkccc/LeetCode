class Solution:
  def lexicographicallySmallestArray(
      self,
      nums: list[int],
      limit: int,
  ) -> list[int]:
    ans = [0] * len(nums)
    numAndIndexes = sorted([(num, i) for i, num in enumerate(nums)])
    # [[(num, index)]], where the difference between in each pair in each
    # `[(num, index)]` group <= `limit`
    numAndIndexesGroups: list[list[tuple[int, int]]] = []

    for numAndIndex in numAndIndexes:
      if (not numAndIndexesGroups or
              numAndIndex[0] - numAndIndexesGroups[-1][-1][0] > limit):
        # Start a new group.
        numAndIndexesGroups.append([numAndIndex])
      else:
        # Append to the existing group.
        numAndIndexesGroups[-1].append(numAndIndex)

    for numAndIndexesGroup in numAndIndexesGroups:
      sortedNums = [num for num, _ in numAndIndexesGroup]
      sortedIndices = sorted([index for _, index in numAndIndexesGroup])
      for num, index in zip(sortedNums, sortedIndices):
        ans[index] = num

    return ans
