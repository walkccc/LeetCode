class Solution:
  def countCharacters(self, words: List[str], chars: str) -> int:
    ans = 0
    count = collections.Counter(chars)

    for word in words:
      tempCount = count.copy()
      for c in word:
        tempCount[c] -= 1
        if tempCount[c] < 0:
          ans -= len(word)
          break
      ans += len(word)

    return ans
