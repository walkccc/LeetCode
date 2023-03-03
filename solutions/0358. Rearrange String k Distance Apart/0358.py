class Solution:
  def rearrangeString(self, s: str, k: int) -> str:
    n = len(s)
    ans = []
    count = collections.Counter(s)
    # valid[i] := the leftmost index i can appear
    valid = collections.Counter()

    # Returns the letter that has most count and also valid
    def getBestLetter(index: int) -> chr:
      maxCount = -1
      bestLetter = '*'

      for c in string.ascii_lowercase:
        if count[c] > 0 and count[c] > maxCount and index >= valid[c]:
          bestLetter = c
          maxCount = count[c]

      return bestLetter

    for i in range(n):
      c = getBestLetter(i)
      if c == '*':
        return ''
      ans.append(c)
      count[c] -= 1
      valid[c] = i + k

    return ''.join(ans)
