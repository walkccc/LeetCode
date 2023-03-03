class Solution:
  def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
    # prefix[i] := # of first i words that start and end with a vowel.
    prefix = [0] * (len(words) + 1)

    for i, word in enumerate(words):
      prefix[i + 1] += prefix[i] + (word[0] in 'aeiou' and word[-1] in 'aeiou')

    return [prefix[r + 1] - prefix[l]
            for l, r in queries]
