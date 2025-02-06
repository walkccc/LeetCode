class Solution:
  def removeDuplicateLetters(self, s: str) -> str:
    ans = []
    count = collections.Counter(s)
    used = [False] * 26

    for c in s:
      count[c] -= 1
      if used[string.ascii_lowercase.index(c)]:
        continue
      while ans and ans[-1] > c and count[ans[-1]] > 0:
        used[ord(ans[-1]) - ord('a')] = False
        ans.pop()
      ans.append(c)
      used[ord(ans[-1]) - ord('a')] = True

    return ''.join(ans)
