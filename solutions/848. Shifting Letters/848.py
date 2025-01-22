class Solution:
  def shiftingLetters(self, s: str, shifts: list[int]) -> str:
    ans = []

    for i in reversed(range(len(shifts) - 1)):
      shifts[i] += shifts[i + 1]

    for c, shift in zip(s, shifts):
      ans.append(chr((string.ascii_lowercase.index(c) + shift) % 26 + ord('a')))

    return ''.join(ans)
