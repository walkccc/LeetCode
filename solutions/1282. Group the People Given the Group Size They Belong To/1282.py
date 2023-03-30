class Solution:
  def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
    ans = []
    groupSizeToIndices = defaultdict(list)

    for i, groupSize in enumerate(groupSizes):
      groupSizeToIndices[groupSize].append(i)

    for groupSize, indices in groupSizeToIndices.items():
      groupIndices = []
      for index in indices:
        groupIndices.append(index)
        if len(groupIndices) == groupSize:
          ans.append(groupIndices.copy())
          groupIndices.clear()

    return ans
