class Solution:
  def numberOfWays(self, s: str) -> int:
    ans = 0
    # before[i] := # of i before current char
    before = [0] * 2
    # after[i] := # of i after current char
    after = [0] * 2
    after[0] = s.count('0')
    after[1] = len(s) - after[0]

    for c in s:
      num = ord(c) - ord('0')
      after[num] -= 1
      if num == 0:
        ans += before[1] * after[1]
      else:
        ans += before[0] * after[0]
      before[num] += 1

    return ans
