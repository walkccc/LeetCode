class Solution:
  def numSpecialEquivGroups(self, words: List[str]) -> int:
    return len({''.join(sorted(word[::2])) + ''.join(sorted(word[1::2]))
                for word in words})
