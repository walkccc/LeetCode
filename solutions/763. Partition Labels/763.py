class Solution:
  def partitionLabels(self, s: str) -> List[int]:
    ans = []
    letterToRightmostIndex = {c: i for i, c in enumerate(s)}

    l = 0  # the leftmost index of the current running string
    r = 0  # the rightmost index of the current running string

    for i, c in enumerate(s):
      r = max(r, letterToRightmostIndex[c])
      if i == r:
        ans.append(r - l + 1)
        l = r + 1

    return ans
