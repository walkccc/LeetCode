class Solution:
  def pathInZigZagTree(self, label: int) -> list[int]:
    def boundarySum(level: int):
      return 2**level + 2**(level + 1) - 1

    ans = []

    for l in range(21):
      if 2**l > label:
        level = l - 1
        break

    if level % 2 == 1:
      label = boundarySum(level) - label

    for l in reversed(range(level + 1)):
      ans.append(label if l % 2 == 0 else boundarySum(l) - label)
      label //= 2

    return ans[::-1]
