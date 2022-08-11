class Solution:
  def toGoatLatin(self, S: str) -> str:
    ans = ''
    vowels = 'aeiouAEIOU'
    words = S.split()
    i = 1

    for word in words:
      if i > 1:
        ans += ' '
      if word[0] in vowels:
        ans += word
      else:
        ans += word[1:] + word[0]
      ans += 'ma' + 'a' * i
      i += 1

    return ans
