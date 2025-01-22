class Solution:
  def minimizeStringValue(self, s: str) -> str:
    ans = []
    count = collections.Counter(s)
    letters = []

    del count['?']

    def getMinFreqLetter(count: dict[str, int]) -> str:
      minFreqLetter = 'a'
      for c in string.ascii_lowercase:
        if count[c] < count[minFreqLetter]:
          minFreqLetter = c
      return minFreqLetter

    for c in s:
      if c == '?':
        minFreqLetter = getMinFreqLetter(count)
        letters.append(minFreqLetter)
        count[minFreqLetter] += 1

    letters.sort()
    i = 0  # letters' index

    for c in s:
      if c == '?':
        ans.append(letters[i])
        i += 1
      else:
        ans.append(c)

    return ''.join(ans)
