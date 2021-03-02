class Solution:
  def diStringMatch(self, S: str) -> List[int]:
    ans = []
    mini = 0
    maxi = len(S)

    for c in S:
      if c == 'I':
        ans.append(mini)
        mini += 1
      else:
        ans.append(maxi)
        maxi -= 1
    ans.append(mini)

    return ans
