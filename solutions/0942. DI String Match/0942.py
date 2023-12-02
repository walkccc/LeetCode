class Solution:
  def diStringMatch(self, s: str) -> List[int]:
    ans = []
    mini = 0
    maxi = len(s)

    for c in s:
      if c == 'I':
        ans.append(mini)
        mini += 1
      else:
        ans.append(maxi)
        maxi -= 1

    return ans + [mini]
