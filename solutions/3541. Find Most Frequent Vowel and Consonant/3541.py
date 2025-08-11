class Solution:
  def maxFreqSum(self, s: str) -> int:
    VOWELS = 'aeiou'
    count = collections.Counter(s)
    maxVowel = max((count[c] for c in VOWELS if c in count), default=0)
    maxConsonant = max((count[c] for c in count if c not in VOWELS), default=0)
    return maxVowel + maxConsonant
