class Solution:
  def reverseOnlyLetters(self, s: str) -> str:
    ans = list(s)
    i = 0
    j = len(s) - 1

    while i < j:
      while i < j and not s[i].isalpha():
        i += 1
      while i < j and not s[j].isalpha():
        j -= 1
      ans[i], ans[j] = ans[j], ans[i]
      i += 1
      j -= 1

    return ''.join(ans)
