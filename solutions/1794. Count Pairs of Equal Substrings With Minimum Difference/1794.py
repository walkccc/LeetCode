class Solution:
  def countQuadruples(self, s1: str, s2: str) -> int:
    # To minimize j - a, the length of the substring should be 1. This is
    # because for substrings with a size greater than 1, a will decrease,
    # causing j - a to become larger.
    ans = 0
    diff = math.inf  # diff := j - a
    firstJ = {}
    lastA = {}

    for j in range(len(s1) - 1, -1, -1):
      firstJ[s1[j]] = j

    for a in range(len(s2)):
      lastA[s2[a]] = a

    for c in string.ascii_lowercase:
      if c not in firstJ or c not in lastA:
        continue
      if firstJ[c] - lastA[c] < diff:
        diff = firstJ[c] - lastA[c]
        ans = 0
      if firstJ[c] - lastA[c] == diff:
        ans += 1

    return ans
