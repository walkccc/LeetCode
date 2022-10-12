class Solution:
  def smallestSubsequence(self, text: str) -> str:
    ans = []
    count = Counter(text)
    used = [False] * 26

    for c in text:
      count[c] -= 1
      if used[ord(c) - ord('a')]:
        continue
      while ans and ans[-1] > c and count[ans[-1]] > 0:
        used[ord(ans[-1]) - ord('a')] = False
        ans.pop()
      ans.append(c)
      used[ord(ans[-1]) - ord('a')] = True

    return ''.join(ans)
