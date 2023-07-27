class Solution:
  def checkIfCanBreak(self, s1: str, s2: str) -> bool:
    count = collections.Counter(s1)
    count.subtract(collections.Counter(s2))

    for a, b in itertools.pairwise(string.ascii_lowercase):
      count[b] += count[a]

    return all(value <= 0 for value in count.values()) or \
        all(value >= 0 for value in count.values())
