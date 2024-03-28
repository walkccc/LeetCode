class Solution:
  def splitWordsBySeparator(self, words: List[str], separator: str) -> List[str]:
    return [splitWord
            for word in words
            for splitWord in word.split(separator)
            if splitWord]
