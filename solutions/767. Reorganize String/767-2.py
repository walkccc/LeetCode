class Solution:
  def reorganizeString(self, s: str) -> str:
    n = len(s)
    count = collections.Counter(s)
    maxCount = max(count.values())

    if maxCount > (n + 1) // 2:
      return ''

    if maxCount == (n + 1) // 2:
      maxLetter = max(count, key=count.get)
      ans = [maxLetter if i % 2 == 0 else '' for i in range(n)]
      del count[maxLetter]
      i = 1
    else:
      ans = [''] * n
      i = 0

    for c, freq in count.items():
      for _ in range(freq):
        ans[i] = c
        i += 2
        if i >= n:
          i = 1

    return ''.join(ans)
