# """
# This is Master's API interface.
# You should not implement it, or speculate about its implementation
# """
# Class Master:
#   def guess(self, word: str) -> int:

class Solution:
  def findSecretWord(self, words: list[str], master: 'Master') -> None:
    for _ in range(10):
      guessedWord = words[random.randint(0, len(words) - 1)]
      matches = master.guess(guessedWord)
      if matches == 6:
        break
      words = [
          word for word in words
          if sum(c1 == c2 for c1, c2 in zip(guessedWord, word)) == matches]
