class Solution:
  def diStringMatch(self, s: str) -> list[int]:
    ans = []
    mn = 0
    mx = len(s)

    for c in s:
      if c == 'I':
        ans.append(mn)
        mn += 1
      else:
        ans.append(mx)
        mx -= 1

    return ans + [mn]
