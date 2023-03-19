class Solution:
  def vowelStrings(self, words: List[str], left: int, right: int) -> int:
    vowels = 'aeiou'
    return sum(word[0] in vowels and word[-1] in vowels
               for word in words[left:right + 1])
