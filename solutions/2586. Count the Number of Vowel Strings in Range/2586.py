class Solution:
  def vowelStrings(self, words: list[str], left: int, right: int) -> int:
    VOWELS = 'aeiou'
    return sum(word[0] in VOWELS and word[-1] in VOWELS
               for word in words[left:right + 1])
