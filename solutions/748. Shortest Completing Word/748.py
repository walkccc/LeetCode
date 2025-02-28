class Solution:
  def shortestCompletingWord(self, licensePlate: str, words: list[str]) -> str:
    def isMatch(word: str) -> bool:
      wordCount = collections.Counter(word)
      return False if any(
          wordCount[i] < count[i] for i in string.ascii_letters) else True

    ans = '*' * 16
    count = collections.defaultdict(int)

    for c in licensePlate:
      if c.isalpha():
        count[c.lower()] += 1

    for word in words:
      if len(word) < len(ans) and isMatch(word):
        ans = word

    return ans
