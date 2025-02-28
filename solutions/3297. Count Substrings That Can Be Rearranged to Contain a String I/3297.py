class Solution:
  def validSubstringCount(self, word1: str, word2: str) -> int:
    ans = 0
    count = collections.Counter(word2)
    required = len(word2)

    l = 0
    for r, c in enumerate(word1):
      count[c] -= 1
      if count[c] >= 0:
        required -= 1
      while required == 0:
        # Add valid substrings containing word1[l..r] to the answer. They are
        # word1[l..r], word1[l..r + 1], ..., word1[l..n - 1].
        ans += len(word1) - r
        count[word1[l]] += 1
        if count[word1[l]] > 0:
          required += 1
        l += 1

    return ans
