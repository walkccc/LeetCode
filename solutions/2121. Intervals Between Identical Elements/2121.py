class Solution:
  def getDistances(self, arr: list[int]) -> list[int]:
    prefix = [0] * len(arr)
    suffix = [0] * len(arr)
    numToIndices = collections.defaultdict(list)

    for i, a in enumerate(arr):
      numToIndices[a].append(i)

    for indices in numToIndices.values():
      for i in range(1, len(indices)):
        currIndex = indices[i]
        prevIndex = indices[i - 1]
        prefix[currIndex] += prefix[prevIndex] + i * (currIndex - prevIndex)
      for i in range(len(indices) - 2, -1, -1):
        currIndex = indices[i]
        prevIndex = indices[i + 1]
        suffix[currIndex] += (suffix[prevIndex] +
                              (len(indices) - i - 1) * (prevIndex - currIndex))

    return [p + s for p, s in zip(prefix, suffix)]
