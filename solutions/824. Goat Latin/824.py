class Solution:
  def toGoatLatin(self, sentence: str) -> str:
    ans = []
    VOWELS = 'aeiouAEIOU'

    i = 1
    for word in sentence.split():
      if i > 1:
        ans.append(' ')
      if word[0] in VOWELS:
        ans.append(word)
      else:
        ans.append(word[1:] + word[0])
      ans.append('ma' + 'a' * i)
      i += 1

    return ''.join(ans)
