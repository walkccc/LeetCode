class Solution:
  def findAllConcatenatedWordsInADict(self, words: list[str]) -> list[str]:
    wordSet = set(words)

    @functools.lru_cache(None)
    def isConcat(word: str) -> bool:
      for i in range(1, len(word)):
        prefix = word[:i]
        suffix = word[i:]
        if prefix in wordSet and (suffix in wordSet or isConcat(suffix)):
          return True

      return False

    return [word for word in words if isConcat(word)]
