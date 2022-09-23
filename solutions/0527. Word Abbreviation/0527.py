class Solution:
  def wordsAbbreviation(self, words: List[str]) -> List[str]:
    n = len(words)

    def getAbbrev(s: str, prefixIndex: int) -> str:
      n = len(s)
      num = n - (prefixIndex + 1) - 1
      numLength = 1 if num < 10 else (2 if num < 100 else 3)
      abbrevLength = (prefixIndex + 1) + numLength + 1
      if abbrevLength >= n:
        return s
      return s[:prefixIndex + 1] + str(num) + s[-1]

    ans = [getAbbrev(word, 0) for word in words]
    # prefix[i] := ans[i] takes words[i][0..prefix[i]]
    prefix = [0] * n

    for i in range(n):
      while True:
        dupeIndices = []
        for j in range(i + 1, n):
          if ans[i] == ans[j]:
            dupeIndices.append(j)
        if not dupeIndices:
          break
        dupeIndices.append(i)
        for index in dupeIndices:
          prefix[index] += 1
          ans[index] = getAbbrev(words[index], prefix[index])

    return ans
