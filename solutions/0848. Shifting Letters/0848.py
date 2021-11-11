class Solution:
  def shiftingLetters(self, S: str, shifts: List[int]) -> str:
    ans = ''

    for i in range(len(shifts) - 2, -1, -1):
      shifts[i] += shifts[i + 1]

    for c, shift in zip(S, shifts):
      ans += chr((ord(c) - ord('a') + shift) % 26 + ord('a'))

    return ans
