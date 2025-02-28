class Solution:
  def reportSpam(self, message: list[str], bannedWords: list[str]) -> bool:
    bannedWordsSet = set(bannedWords)
    return sum(word in bannedWordsSet for word in message) > 1
