class Solution:
  # Similar to 859. Buddy Strings
  def areAlmostEqual(self, s1: str, s2: str) -> bool:
    diffIndices = [i for i, (a, b) in enumerate(zip(s1, s2))
                   if a != b]
    return not diffIndices or (len(diffIndices) == 2 and
                               s1[diffIndices[0]] == s2[diffIndices[1]] and
                               s1[diffIndices[1]] == s2[diffIndices[0]])
