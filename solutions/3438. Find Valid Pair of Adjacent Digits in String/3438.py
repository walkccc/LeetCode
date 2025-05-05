class Solution:
  def findValidPair(self, s: str) -> str:
    count = collections.Counter(s)
    return next((a + b
                for a, b in itertools.pairwise(s)
                if a != b and count[a] == int(a) and count[b] == int(b)), '')
