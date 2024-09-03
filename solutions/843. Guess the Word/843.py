# """
# This is Master's API interface.
# You should not implement it, or speculate about its implementation
# """
# Class Master:
#   def guess(self, word: str) -> int:

class Solution:
  def findSecretWord(self, wordlist: list[str], master: 'Master') -> None:
    def getMatches(s1: str, s2: str) -> int:
      matches = 0
      for c1, c2 in zip(s1, s2):
        if c1 == c2:
          matches += 1
      return matches

    for _ in range(10):
      guessedWord = wordlist[random.randint(0, len(wordlist) - 1)]
      matches = master.guess(guessedWord)
      if matches == 6:
        break
      wordlist = [
          word for word in wordlist
          if getMatches(guessedWord, word) == matches]
