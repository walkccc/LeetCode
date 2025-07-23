class Solution:
  def shiftingLetters(self, s: str, shifts: list[list[int]]) -> str:
    ans = []
    currShift = 0
    line = [0] * (len(s) + 1)

    for start, end, direction in shifts:
      diff = 1 if direction else -1
      line[start] += diff
      line[end + 1] -= diff

    for i, c in enumerate(s):
      currShift = (currShift + line[i]) % 26
      num = (ord(c) - ord('a') + currShift + 26) % 26
      ans.append(chr(ord('a') + num))

    return ''.join(ans)
