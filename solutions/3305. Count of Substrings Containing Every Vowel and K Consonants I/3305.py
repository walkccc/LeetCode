class Solution:
  def countOfSubstrings(self, word: str, k: int) -> int:
    kVowels = 'aeiou'

    def substringsWithAtMost(k: int) -> int:
      """
      Return the number of substrings containing every vowel with at most k
      consonants.
      """
      if k == -1:
        return 0

      res = 0
      vowels = 0
      uniqueVowels = 0
      vowelLastSeen = {}

      l = 0
      for r, c in enumerate(word):
        if c in kVowels:
          vowels += 1
          if c not in vowelLastSeen or vowelLastSeen[c] < l:
            uniqueVowels += 1
          vowelLastSeen[c] = r
        while r - l + 1 - vowels > k:
          if word[l] in kVowels:
            vowels -= 1
            if vowelLastSeen[word[l]] == l:
              uniqueVowels -= 1
          l += 1
        if uniqueVowels == 5:
          # Add substrings containing every vowel with at most k consonants to
          # the answer. They are
          # word[l..r], word[l + 1..r], ..., word[min(vowelLastSeen[vowel])..r]
          res += min(vowelLastSeen[vowel] for vowel in kVowels) - l + 1

      return res

    return substringsWithAtMost(k) - substringsWithAtMost(k - 1)
