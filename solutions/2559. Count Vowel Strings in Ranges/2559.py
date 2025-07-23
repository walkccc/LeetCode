class Solution:
  def vowelStrings(
      self,
      words: list[str],
      queries: list[list[int]],
  ) -> list[int]:
    VOWELS = 'aeiou'
    # prefix[i] := the number of the first i words that start with and end in a vowel
    prefix = [0] * (len(words) + 1)

    for i, word in enumerate(words):
      prefix[i + 1] += prefix[i] + (word[0] in VOWELS and word[-1] in VOWELS)

    return [prefix[r + 1] - prefix[l]
            for l, r in queries]
