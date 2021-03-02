class Solution:
  def freqAlphabets(self, s: str) -> str:
    ans = ''
    i = 0

    while i < len(s):
      if i + 2 < len(s) and s[i + 2] == '#':
        ans += chr(int(s[i:i + 2]) + ord('a') - 1)
        i += 3
      else:
        ans += chr(int(s[i]) + ord('a') - 1)
        i += 1

    return ans
