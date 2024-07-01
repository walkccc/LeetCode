class Solution:
  def pathInZigZagTree(self, label: int) -> List[int]:
    def boundarySum(level: int):
      return 2**level + 2**(level + 1) - 1

    ans = []

    for l in range(21):
      if 2**l > label:
        level = l - 1
        break

    if level & 1:
      label = boundarySum(level) - label

    for l in reversed(range(level + 1)):
      ans.append(boundarySum(l) - label if l & 1 else label)
      label //= 2

    return ans[::-1]
