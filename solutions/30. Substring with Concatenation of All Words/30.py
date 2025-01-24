class Solution:
  def findSubstring(self, s: str, words: list[str]) -> list[int]:
    if len(s) == 0 or words == []:
      return []

    k = len(words)
    n = len(words[0])
    ans = []
    count = collections.Counter(words)

    for i in range(len(s) - k * n + 1):
      seen = collections.defaultdict(int)
      j = 0
      while j < k:
        word = s[i + j * n: i + j * n + n]
        seen[word] += 1
        if seen[word] > count[word]:
          break
        j += 1
      if j == k:
        ans.append(i)

    return ans
