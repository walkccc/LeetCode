class Solution:
  def vowelStrings(self, words: List[str], left: int, right: int) -> int:
    kVowels = 'aeiou'
    return sum(word[0] in kVowels and word[-1] in kVowels
               for word in words[left:right + 1])
