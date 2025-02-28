class Solution:
  def stringSequence(self, target: str) -> list[str]:
    ans = []
    s = []

    for targetChar in target:
      s.append('a')
      ans.append(''.join(s))
      for offset in range(ord('b'), ord(targetChar) + 1):
        s[-1] = chr(offset)
        ans.append(''.join(s))

    return ans
