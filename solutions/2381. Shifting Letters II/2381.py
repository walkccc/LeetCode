class Solution:
  def shiftingLetters(self, s: str, shifts: list[list[int]]) -> str:
    ans = []
    currShift = 0
    timeline = [0] * (len(s) + 1)

    for start, end, direction in shifts:
      diff = 1 if direction else -1
      timeline[start] += diff
      timeline[end + 1] -= diff

    for i, c in enumerate(s):
      currShift = (currShift + timeline[i]) % 26
      num = (string.ascii_lowercase.index(c) + currShift + 26) % 26
      ans.append(chr(ord('a') + num))

    return ''.join(ans)
