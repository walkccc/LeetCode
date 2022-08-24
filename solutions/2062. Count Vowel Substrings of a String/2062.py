class Solution:
  def countVowelSubstrings(self, word: str) -> int:
    def countVowelSubstringsAtMost(goal: int) -> int:
      ans = 0
      k = goal
      count = Counter()

      l = 0
      for r, c in enumerate(word):
        if c not in 'aeiou':  # fresh start
          l = r + 1
          k = goal
          count = Counter()
          continue
        count[c] += 1
        if count[c] == 1:
          k -= 1
        while k == -1:
          count[word[l]] -= 1
          if count[word[l]] == 0:
            k += 1
          l += 1
        ans += r - l + 1  # s[l..r], s[l + 1..r], ..., s[r]

      return ans

    return countVowelSubstringsAtMost(5) - countVowelSubstringsAtMost(4)
