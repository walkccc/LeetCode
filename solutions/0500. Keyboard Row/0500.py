class Solution:
  def findWords(self, words: List[str]) -> List[str]:
    ans = []
    rows = [set('qwertyuiop'), set('asdfghjkl'), set('zxcvbnm')]

    for word in words:
      lowerWord = set(word.lower())
      if any(lowerWord <= row for row in rows):
        ans.append(word)

    return ans
