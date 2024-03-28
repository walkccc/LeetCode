class Solution:
  def checkStrings(self, s1: str, s2: str) -> bool:
    count = [collections.Counter() for _ in range(2)]

    for i, (a, b) in enumerate(zip(s1, s2)):
      count[i % 2][a] += 1
      count[i % 2][b] -= 1

    return all(freq == 0 for freq in count[0].values()) \
        and all(freq == 0 for freq in count[1].values())
